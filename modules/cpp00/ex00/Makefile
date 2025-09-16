NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
MK = make
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re

.SECONDARY:
