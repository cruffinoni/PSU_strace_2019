##
## EPITECH PROJECT, 2018
## makefile
## File description:
## This file is used for compilation of every files to make a binary file.
##
MAIN_FILE		=	./src/main.c
SRC				=

NAME			=	strace

SRC_TEST		=	./tests/test.c
NAME_TEST		=	test_strace

INCLUDE_PATH	=	./include/

CFLAGS			=	-Wall -Wextra -I $(INCLUDE_PATH)

OBJ				=	$(SRC:.c=.o)
OBJ_MAIN		=	$(MAIN_FILE:.c=.o)

$(NAME): $(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS)

all: $(NAME)

debug:
	gcc -o $(NAME) $(SRC) $(SRC_CMDS) $(MAIN_FILE) $(CFLAGS) -g

tests_run: all
	gcc $(CFLAGS) $(SRC_TEST) -o test_nm
	#gcc -o $(NAME_TEST) $(SRC_TEST) $(SRC) $(CFLAGS) -lcriterion --coverage

clean:
	@rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)

fclean:
	@rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)
	@rm -f $(NAME) $(NAME_TEST)

re:	fclean all

.PHONY:	all clean fclean re debug
