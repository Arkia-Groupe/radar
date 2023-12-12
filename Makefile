##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to build project
##

NAME    =       my_radar

SRCS = src/main.c \
       src/utils/print_usages.c

CC = gcc

CFLAGS = -Iinclude -Llib/my -lmy -l csfml-graphics -l csfml-system -l csfml-window

all:  $(NAME)

$(NAME):
	cd lib/my && make
	$(CC) $(SRCS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) *.o
	$(RM) $(OBJS)

fclean: clean
	cd lib/my && make fclean
	$(RM) $(NAME)

re:     fclean all

asan: fclean
	cd lib/my && make
	$(CC) $(SRCS) -o $(NAME) -lasan -g3 $(CFLAGS)
