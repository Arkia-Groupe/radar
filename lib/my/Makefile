##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to build project
##

NAME	=	libmy.a

SRCS = my_compute_power_rec.c \
       my_compute_square_root.c \
	   my_put_float.c \
	   my_put_float_upper.c \
       my_put_address.c \
       my_isneg.c \
       my_put_nbr.c \
       my_put_unsigned_nbr.c \
       my_put_hexa.c \
       my_put_hexa_upper.c \
       my_put_octal.c \
       my_putchar.c \
       my_putstr.c \
       my_revstr.c \
       my_show_word_array.c \
       my_strcat.c \
       my_strcmp.c \
       my_strcpy.c \
       my_strdup.c \
       my_strlen.c \
       my_strncat.c \
       my_strncpy.c \
       my_swap.c \
	   my_printf.c \
	   my_format.c \
	   my_error.c \
	   my_strpop.c


OBJS	=	$(SRCS:.c=.o)

CC = gcc

CFLAGS = -c -Iinclude -Wall -Wextra -Werror

all:  $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) *.o
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
