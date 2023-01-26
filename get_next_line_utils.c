/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:56 by acouture          #+#    #+#             */
/*   Updated: 2023/01/26 11:57:37 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *saved, char *buf)
{
	char			*join_str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!saved)
	{
		saved = (char*)malloc(sizeof(char) * 1);
		saved[0] = '\0';
	}
	if (!saved || !buf)
		return (NULL);
	join_str = malloc((((ft_strlen(saved)) + ft_strlen(buf)) + 1) * sizeof(char));
	if (join_str == NULL)
		return (NULL);
	while (saved[i])
	{
		join_str[i] = saved[i];
		i++;
	}
	while (buf[j])
		join_str[i++] = buf[j++];
	join_str[i] = '\0';
	free(saved);
	return (join_str);
}


char	*get_line_out(char *saved)
{
	int i;
	char *str;

	i = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		++i;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n' )
	{
		str[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		str[i] = saved[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}