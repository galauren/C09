#!/bin/sh

NAME=libft

cc -Wall -Wextra -Werror -c \
	ft_putchar.c\
	ft_swap.c\
	ft_strlen.c\
	ft_putstr.c\
	ft_strcmp.c

ar rcs $NAME.a\
	ft_putchar.o\
	ft_swap.o\
	ft_strlen.o\
	ft_putstr.o\
	ft_strcmp.o

rm ./*.o
