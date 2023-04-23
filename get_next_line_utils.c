/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:56 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 12:44:17 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculates the length of a given string
 * @param str The string to calculate the length of
 * @return The length of the given string
 */
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * Searches for the first occurrence of a character in a given string.
 * Returns a pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 * @param str The string to search in.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of the character in the string,
	or NULL if not found.
*/
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

/**
 * Helper function for ft_strjoin that allocates memory for the new string.
 * Returns a pointer to the new string, or NULL if memory allocation fails.
 * @param saved The first string to concatenate.
 * @param buf The second string to concatenate.
 * @return A pointer to the newly allocated string,
	or NULL if memory allocation fails.
*/
char	*malloc_join(char *saved, char *buf)
{
	char	*str;

	str = malloc((((ft_strlen(saved)) + ft_strlen(buf)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}

/**
 * Concatenates two strings and returns a pointer to the newly concatenated string.
 * Frees the memory allocated for the first string and returns the new string.
 * Returns NULL if either of the input strings are NULL or if memory allocation fails.
 * @param saved The first string to concatenate.
 * @param buf The second string to concatenate.
 * @return A pointer to the newly concatenated string, or NULL if concatenation or memory allocation fails.
*/
char	*ft_strjoin(char *saved, char *buf)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!saved)
	{
		saved = (char *)malloc(sizeof(char) * 1);
		saved[0] = '\0';
	}
	if (!saved || !buf)
		return (NULL);
	str = malloc_join(saved, buf);
	while (saved[i])
	{
		str[i] = saved[i];
		i++;
	}
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	free(saved);
	return (str);
}

/**
 * Takes a saved string and returns a new string consisting of all the characters before
 * the first occurrence of a newline character, including the newline character.
 * Returns NULL if the saved string is empty or if memory allocation fails.
 * @param saved The saved string to create a new string from.
 * @return The new string, or NULL if the saved string is empty or if memory allocation fails.
*/
char	*get_line_out(char *saved)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		str[j++] = saved[i++];
	if (saved[i] == '\n')
		str[j++] = saved[i++];
	str[j] = '\0';
	return (str);
}
