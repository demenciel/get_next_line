/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:32 by acouture          #+#    #+#             */
/*   Updated: 2023/01/26 13:51:28 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_saved(int fd, char *saved);
char	*get_next_line(int fd);
char	*get_line_out(char *saved);
char	*read_new_saved(char *saved);
char	*malloc_join(char *saved, char *buf);

#endif