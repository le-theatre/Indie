NAME	=	ex01

SRC	=	main.cpp

CPPFLAGS	=	-I../../../

CXXFLAGS	=	-std=c++17 -Wall -Wextra

LDFLAGS	=	-lsfml-graphics -lsfml-system -lsfml-window

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all $(NAME) clean fclean re
