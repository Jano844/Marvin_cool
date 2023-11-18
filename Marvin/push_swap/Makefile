CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
HEADER = push_swap.h
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = action_orders.c action_orders_two.c action_orders_three.c \
error_check_one.c error_check_two.c error_message.c find_positions.c \
helper_functions.c indexing.c modified_list_functions.c push_swap.c \
small_algo.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -g -o $(NAME)_debug $(OBJS) $(LIBFT)