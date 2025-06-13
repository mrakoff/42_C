# compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I include

NAME = push_swap

# source files etc
LIBFT_PATH = include/libft

PRINTF = include/printf/ft_printf.c \
		include/printf/ft_printf_ft.c \
		include/printf/ft_put.c

LIBFT= $(LIBFT_PATH)/libft.a
SRCS = $(PRINTF) \
		src/main.c src/process_input.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)


# compilation
$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) \
		-L$(LIBFT_PATH) -lft\
		-o $(NAME)


# utility rules
clean:
	-$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re