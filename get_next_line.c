/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:36 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 12:41:10 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Set a memory block to 0
 * This function sets the first 'n' bytes pointed to by s to zero
 * @param s Pointer to the memory area to be zeroed
 * @param n Number of bytes to be zeroed
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (!s)
		return ;
	p = s;
	while (n--)
		*p++ = 0;
}

/**
 * @brief This function allocates and zero-initialize an array
 * This function allocates memory for an array of size 'counts' elements,
 *		and each of size 'size', and initializes all bytes in the array to zero
 * @param count The number of elements in the array
 * @param size The byte size of the elements of the array
 */
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

/**
 * Reads from a file descriptor and concatenates the read content to a given string.
 * Continues reading until a newline character is encountered in the saved string
 * or until the end of the file is reached. Returns the concatenated string.
 * If an error occurs during reading, frees memory and returns NULL.
 * @param fd The file descriptor to read from.
 * @param saved The string to concatenate the read content to.
 * @return The concatenated string, or NULL if an error occurs.
*/
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

/**
 * Takes a saved string and returns a new string starting from the first character after
 * the first newline character. If there is no newline character in the saved string,
 * frees memory and returns NULL. Returns the new string.
 * @param saved The saved string to create a new string from.
 * @return The new string, or NULL if there is no newline character in the saved string.
*/
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

/**
 * @brief This function is meant to read a line from a file descriptor
 * @param fd A file descriptor
 * @return The line that was read from the file descriptor
 */
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
