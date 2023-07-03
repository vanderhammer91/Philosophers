# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 15:10:22 by ivanderw          #+#    #+#              #
#    Updated: 2023/07/02 12:26:53 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC_FLAGS = gcc -Wall -Wextra -Werror -I includes\
			-framework AppKit -fsanitize=address -g

SOURCE  = 	source/main.c							\
			source/utilities/init_utils.c			\
			source/utilities/list_utils.c			\
			source/utilities/misc_utils.c			\
			source/utilities/monitor_routine.c		\
			source/utilities/philo_routine.c		\
			source/utilities/philo_utils.c			\
			source/utilities/routine_utils.c		\

all: $(NAME)

OBJECTS = $(source:%.c=%.o)

%.o: %.c
	$(CC_FLAGS) -o $@ -c $<

$(NAME):
	$(CC_FLAGS) $(SOURCE) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM

re : fclean all

.PHONY: all clean fclean re
