/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:36 by acouture          #+#    #+#             */
/*   Updated: 2023/04/19 14:57:39 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (!s)
		return ;
	p = s;
	while (n--)
		*p++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = (count * size);
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, total_size);
	return (ptr);
}

char	*read_saved(int fd, char *saved)
{
	int		bytes_read;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(saved);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	free(buf);
	return (saved);
}

char	*read_new_saved(char *saved)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), (ft_strlen(saved) - i) + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (saved[i])
		str[j++] = saved[i++];
	str[j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved = read_saved(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line_out(saved);
	saved = read_new_saved(saved);
	return (line);
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
