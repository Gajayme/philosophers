NAME	= philo

CC		= gcc -Wall -Wextra -Werror -pthread

T_FLAG	= -fsanitize=thread

E_FLAG	= -pthread

SRC		= $(wildcard *.c)

INC		= philo.h

RM 		= 	rm -f

OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) Makefile $(INC)
			$(CC) $(OBJ) $(E_FLAG) -I$(INC) -o $(NAME)

%.o : %.c 	$(INC)
			$(CC) -c $< -o $@

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
