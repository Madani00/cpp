NAME = exe 
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
MK = make
SRCS = AForm.cpp main.cpp RobotomyRequestForm.cpp Bureaucrat.cpp \
	PresidentialPardonForm.cpp  ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) *shrubbery

fclean: clean
		$(RM) $(NAME)

re: fclean all