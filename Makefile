NAME	= philo

CC		= gcc -Wall -Wextra -Werror -MMD

SRC		= philo.c valid.c lib_utils.c \
			utils.c activities.c\

INC		= philo.h

RM 		= 	rm -f

OBJ		= 	$(patsubst %.c,%.o,$(SRC))

#D_FILES 	= $(patsubst %.c,%.d,$(SRC))

all: 		$(NAME)

$(NAME):	$(OBJ) $(INC)
			$(CC) $(OBJ) -pthread  -o $(NAME)

%.o : %.c 	$(HEADER)
			$(CC) -c $< -o $@

#include $(wildcard $(D_FILES))

clean:
			$(RM) $(OBJ) *.d

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all bonus

.PHONY:		bonus all clean fclean re
