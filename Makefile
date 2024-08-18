CC = cc

SRC = minishell.c doc_2/bases.c lexer.c token.c 

NAME = shell

FLAGS = -Wall -Werror -Wextra -g3 -lreadline -lhistory

OBJ     = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SECONDARY : $(OBJ)

.PHONY : all clean fclean re