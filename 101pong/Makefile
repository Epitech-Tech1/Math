##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC =	101pong.c \

OBJ = 	$(SRC:.c=.o)

NAME = 	101pong

all: 	$(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lm

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re