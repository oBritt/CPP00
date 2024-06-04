CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = account

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re