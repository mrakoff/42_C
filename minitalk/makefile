# compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# executable files names
NAME_SERV = server
NAME_CLIENT = client

# source files etc
PRINTF = printf/ft_printf.c \
		printf/ft_printf_ft.c \
		printf/ft_put.c

SRCS_SERV = server.c utils.c $(PRINTF)
SRCS_CLIENT = client.c utils.c $(PRINTF)

OBJS_SERV = $(SRCS_SERV:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME_SERV) $(NAME_CLIENT)

# compilation
$(NAME_SERV): $(OBJS_SERV)
	$(CC) $(CFLAGS) $(OBJS_SERV) -o $(NAME_SERV)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

# utility rules
clean:
	rm -f $(OBJS_SERV) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERV) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
