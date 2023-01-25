/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:53:42 by acouture          #+#    #+#             */
/*   Updated: 2023/01/25 14:21:13 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main ()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s", get_next_line(fd));
    }
}