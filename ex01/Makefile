CC = gcc -Wall -Wextra -Werror

SRC_DIR = ./srcs
INCL_DIR = ./includes
SRC_NAMES = ft_putchar.c\
        	ft_swap.c\
        	ft_strlen.c\
        	ft_putstr.c\
        	ft_strcmp.c

SRC = $(SRC_NAMES:%=$(SRC_DIR)/%.c)
OBJ_FILES = $(SRC_FILES:%.c=%.o)

EXE = libft.a


all: $(EXE)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I $(INCL_DIR) -c -o $@ $<

$(EXE): $(OBJ_FILES)
	ar rcs $(EXE) ./srcs/*.o


clean :
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all
