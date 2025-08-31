NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f
MK = make

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re

.SECONDARY:
