# compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude
NAME = fractol

# source files etc
LIBFT_PATH = include/libft
MLX_PATH = MLX42

LIBFT= $(LIBFT_PATH)/libft.a

SRCS = src/main.c src/mandelbrot.c src/julia.c src/render.c src/hooks.c \

OBJS = $(SRCS:.c=.o)
MLX_LIB = $(MLX_PATH)/build/libmlx42.a -ldl -lglfw

all: $(LIBFT) $(MLX_LIB) $(NAME)

# compilation
$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_PATH)

$(MLX_LIB):
	@if [ ! -d $(MLX_PATH) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git \
		$(MLX_PATH); \
	fi
	@if [ ! -f $(MLX_PATH)/build/libmlx42.a ]; then \
		cmake $(MLX_PATH) -B $(MLX_PATH)/build && \
		cmake --build $(MLX_PATH)/build ; \
	fi

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) -o $(NAME)

# utility rules
clean:
	-$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(MLX_PATH)/build
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re