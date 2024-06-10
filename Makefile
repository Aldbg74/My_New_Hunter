##
## EPITECH PROJECT, 2024
## My_New_Hunter
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)	\
		$(wildcard src/*.c) \
		$(wildcard lib/my/*.c) \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

EXEC	=	My_Hunter

CFLAGS	+=	-L./lib/my -g3 -lcsfml-graphics

all:	build	clean

build:	${OBJ}	gertrude
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

clean:
	rm -f vgcore.* $(OBJ) *.gch

fclean:	clean
	rm -f $(EXEC)

re:	fclean	all

gertrude:
	@echo -e "\n\n\033[3mGertrude-CLI - Makefile creation tool\033[0m\n"

.PHONY:	all	build	clean	fclean	re
