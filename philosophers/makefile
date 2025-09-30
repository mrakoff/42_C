# compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g # valgrind --tool=helgrind ## -fsanitize=thread -g ## -fsanitize=address
NAME = philo

SRCS = src/init.c src/main.c src/monitor.c src/philo_routine.c src/utils_exec.c src/utils_exec2.c src/utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# compilation
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# utility rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

party: curl parrot.live

.PHONY: all clean fclean re party