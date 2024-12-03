##
## EPITECH PROJECT, 2024
## My_New_Hunter
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)	\
		$(wildcard src/*.c) \
		$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

EXEC	=	my_hunter

CFLAGS	+=	-L./lib/my -g3 -lcsfml-graphics -lcsfml-audio

all:	build	clean

build:	${OBJ}
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

clean:
	$(RM) vgcore.* $(OBJ) *.gch

fclean:	clean
	rm -f $(EXEC)

re:	fclean	all

.PHONY:	all	build	clean	fclean	re
