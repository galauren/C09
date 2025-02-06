CC = gcc -Wall -Wextra -Werror

INCL_DIR = ./includes

SRC_DIR = ./srcs
SRC_NAMES = ft_putchar.c\
        	ft_swap.c\
        	ft_strlen.c\
        	ft_putstr.c\
        	ft_strcmp.c

SRC = 		$(addprefix $(SRC_DIR)/,$(SRC_NAMES))
OBJ_FILES = $(SRC:%.c=%.o)

NAME = libft.a


all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I $(INCL_DIR) -c -o $@ $<

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)


clean :
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
