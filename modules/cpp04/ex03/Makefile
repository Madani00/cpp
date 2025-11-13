NAME = exe 
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
MK = make
SRCS = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  ICharacter.cpp  IMateriaSource.cpp  main.cpp  MateriaSource.cpp
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