CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC = libft
LIB = libft
LIB_AR = $(LIB)/libft.a

SRC_FUN = actions.c algo.c orders.c parser.c print.c qsort.c stack.c
SRC = $(SRC_FUN) main.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = $(SRC_FUN) checker_bonus.c get_line_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap
BONUS = checker

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(LIB_AR):
	$(MAKE) -C $(LIB) bonus

$(NAME): $(LIB_AR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L$(LIB) -lft

clean:
	$(MAKE) -C $(LIB) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIB) fclean
	rm -f $(NAME)

re: fclean
	$(MAKE)

bonus: $(LIB_AR) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(BONUS) -L$(LIB) -lft

.PHONY: all clean fclean re bonus
