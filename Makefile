CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC = libft
LIB = libft

SRC = *.c

NAME = test

all: $(SRC) $(LIB)/libft.a
	make -C $(LIB) bonus
	$(CC) $(CFLAGS) -I$(INC) $(SRC) -o $(NAME) -L$(LIB) -lft
