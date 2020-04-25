##
## EPITECH PROJECT, 2020
## JAM_streetart_2019
## File description:
## Makefile
##

.PHONY			: 	all clean fclean re

NAME			=	escape

SRC 			=	src/States/IntroState.cpp \
					src/States/MenuState.cpp \
					src/States/PlayState.cpp \
					src/States/GameState.cpp \
					src/Engine/State.cpp \
					src/Engine/StateMachine.cpp \
					src/Application.cpp \
					src/main.cpp

OBJ				= 	$(SRC:.cpp=.o)

CC				= 	g++

CFLAGS 			+=  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -Wextra #-Werror

CXXFLAGS        =   -I. -Iinclude

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean			:
					rm -f $(OBJ)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all