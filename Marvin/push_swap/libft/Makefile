CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
HEADER = libft.h
FT_PRINTF_HEADER = print_functions/ft_printf/ft_printf.h
GET_NEXT_LINE_HEADER = print_functions/get_next_line/get_next_line.h
SRCS_DIR = conversion list_functions memory_manipulation print_functions string_checks string_manipulation
SRCS = $(foreach dir,$(SRCS_DIR),$(wildcard $(dir)/*.c))

FT_PRINTF_DIR = print_functions/ft_printf
GET_NEXT_LINE_DIR = print_functions/get_next_line
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c)
GET_NEXT_LINE_SRCS = $(wildcard $(GET_NEXT_LINE_DIR)/*.c)

OBJS = $(SRCS:.c=.o) $(FT_PRINTF_SRCS:.c=.o) $(GET_NEXT_LINE_SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
