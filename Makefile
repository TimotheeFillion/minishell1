##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile files
##

NAME	=	mysh

SRC	=	minishell2.c\
		commands.c\
		get_next_line.c\
		my_str_to_wordtab.c\
		my_strcmp.c\
		my_strlen.c\
		my_getenv.c\
		basic_puts.c\
		my_strcpy.c\
		commands2.c\
		my_unsetenv.c\
		my_cd.c\
		new.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) -Wall -Wextra -g3

clean:
		rm $(OBJ)

fclean:		clean
		rm $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
