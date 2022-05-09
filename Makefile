CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC = libft
LIB = libft

SRC = actions.c algo.c main.c orders.c print.c qsort.c stack.c
OBJ = $(SRC:.c=.o)
LIB_AR = $(LIB)/libft.a

NAME = push_swap

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(LIB_AR):
	$(MAKE) -C $(LIB) bonus

$(NAME): $(OBJ) $(LIB_AR)
	$(CC) $(OBJ) -o $(NAME) -L$(LIB) -lft

clean:
	$(MAKE) -C $(LIB) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIB) fclean
	rm -f $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
