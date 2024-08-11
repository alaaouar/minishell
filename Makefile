CC = cc

SRC = minishell.c

NAME = minishell

#FLAG = -Wall -Werror -Wextra

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SECONDARY : $(OBJ)

.PHONY : all clean fclean re