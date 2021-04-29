##
## EPITECH PROJECT, 2021
## Indie
## File description:
## Makefile
##

NAME	=	indie

SRC	=	src/main.cpp\
		src/server/Server.cpp\

OBJ		=	$(SRC:.cpp=.o)

CC			= g++
CPPFLAGS	= -Wall -Wextra -W -I./include -I./src/server

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) vgcore.* *.gcno *.gcda

fclean: clean
	$(RM) $(OBJ) $(NM)

debug: CPPFLAGS += -g3
debug: re

re:	fclean all

.PHONY: all clean fclean re
