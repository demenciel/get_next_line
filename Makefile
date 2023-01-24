NAME = 		get_next_line

SRC =		get_next_line_utils.c \
			get_next_line.c \
		
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
BUFFER_SIZE = 42

OBJS = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJS)
	@echo "$(GREEN)next_line compiled!$(DEF_COLOR)"

	
clean:
	rm -f $(OBJS)
	@echo "$(BLUE)next_line object files cleaned!$(DEF_COLOR)"


fclean: clean
	rm -f $(NAME)
	@echo "$(CYAN)next_line executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)next_line executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for next_line!$(DEF_COLOR)"

.PHONY: all clean fclean re