/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:36 by acouture          #+#    #+#             */
/*   Updated: 2023/01/23 15:29:10 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static int i;
    char *stored_line;

    i = 0;
    stored_line = malloc(sizeof(char) * BUFFER_SIZE);
    int bytes_read = read(fd, stored_line, BUFFER_SIZE);
    while (stored_line[i] != '\n')
        i++;
    return (stored_line);
}

int main()
{
    int fd = open("README.md", O_RDONLY);
    printf("%s", get_next_line(fd));
}