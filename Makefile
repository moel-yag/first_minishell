CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I./src/utils -I./src/shell -I./src/commands -I./src/parser
SRC = src/main.c \
      src/shell/shell.c \
      src/commands/commands.c \
      src/utils/linked_list.c \
      src/utils/error_handling.c \
      src/parser/parser.c
OBJ = $(SRC:.c=.o)
NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re