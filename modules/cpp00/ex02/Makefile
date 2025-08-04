NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MK = make

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -std=c++98 -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re

.SECONDARY: