NAME	= philo_bonus

CC		= gcc -Wall -Wextra -Werror -pthread

T_FLAG	= -fsanitize=thread

E_FLAG	= -pthread

SRC		= $(wildcard *.c)

INC		= philo_bonus.h

RM 		= 	rm -f

OBJ		= 	$(SRC:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJ) Makefile $(INC)
			$(CC) $(OBJ) $(E_FLAG) -o $(NAME)

%.o : %.c 	$(INC)
			$(CC) -c $< -o $@

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY:		bonus all clean fclean re
