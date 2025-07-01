NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all