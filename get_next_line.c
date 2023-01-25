/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:36 by acouture          #+#    #+#             */
/*   Updated: 2023/01/25 16:24:42 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_saved(int fd, char *saved)
{
	int		bytes_read;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	free(buf);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char *saved;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved = read_saved(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line(saved);
	saved = read_new_saved(saved);
	return (line);
}