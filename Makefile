##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to build project
##

NAME	=	my_radar

LIB	=	libmy.a

LIB_DIR =	lib/my

SRCS = src/main.c \
       src/main2.c \
       src/map.c \
       src/simulation.c \
       src/script.c \
       src/events.c \
       src/simulation2.c \
       src/file_handling.c \
       src/aircraft.c \
       src/collision.c \
       src/init_graphics.c \
       src/control_tower.c \
       src/window.c

OBJS	=	$(SRCS:.c=.o)

LIB_SRCS = $(wildcard $(LIB_DIR)/*.c)

LIB_OBJS = $(LIB_SRCS:.c=.o)

CC = gcc

CFLAGS = -lasan -Iinclude

LDFLAGS = -L$(LIB_DIR) -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lm 

all: $(LIB) $(NAME)

$(LIB): $(LIB_OBJS)
	ar rc $(LIB_DIR)/$(LIB) $(LIB_OBJS)
	rm -f $(LIB_OBJS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) *.o
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIB_DIR)/$(LIB)
	$(RM) $(NAME)

re: fclean all
