NAME	= philo

CC		= gcc -Wall -Wextra -Werror -MMD -fsanitize=thread

E_FLAGS	= -pthread

#MAKEFILE AS A DEPENDENCE
SRC		= philo.c valid.c lib_utils.c \
			utils.c activities.c time_utils.c\
			mem_utils.c \

INC		= philo.h

RM 		= 	rm -f

OBJ		= 	$(patsubst %.c,%.o,$(SRC))

#D_FILES 	= $(patsubst %.c,%.d,$(SRC))

all: 		$(NAME)

$(NAME):	$(OBJ) MAKEFILE $(INC)
			$(CC) $(OBJ) $(E_FLAGS) -o $(NAME)

%.o : %.c 	$(INC) 
			$(CC) -c $< -o $@

#include $(wildcard $(D_FILES))

clean:
			$(RM) $(OBJ) *.d

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all bonus

.PHONY:		bonus all clean fclean re
