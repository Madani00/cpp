NAME = PhoneBook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
MK = make
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re

.SECONDARY:
