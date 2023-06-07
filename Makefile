# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 07:59:44 by acouture          #+#    #+#              #
#    Updated: 2023/05/04 13:39:39 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= get_next
CFLAGS	:= -g -Wextra -Wall -Werror

SRCS	:= ./get_next_line.c \
			./get_next_line_utils.c \

OBJ_PATH = obj/
OBJ = ${SRCS:.c=.o}
OBJS = $(addprefix $(OBJ_PATH), $(OBJ)) 

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)get_next_line was successfully compiled! $(DEF_COLOR)"

clean:
	@rm -rf $(OBJS) $(OBJ_PATH)
	@echo "$(BLUE)get_next_line was successfully cleaned! $(DEF_COLOR)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)get_next_line was successfully cleaned! $(DEF_COLOR)"

bonus: 

re: clean all

.PHONY: all, clean, fclean, re