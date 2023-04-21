# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 07:59:44 by acouture          #+#    #+#              #
#    Updated: 2023/04/21 15:54:57 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= get_next
CFLAGS	:= -g -Wextra -Wall -Werror

SRCS	:= ./get_next_line.c \
			./get_next_line_utils.c \

			
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

run : all
	./get_next

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

debug: $(NAME)
	@$(CC) -g $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re