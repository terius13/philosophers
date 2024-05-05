# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:22:30 by ting              #+#    #+#              #
#    Updated: 2024/05/05 22:29:47 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra -g -lpthread -fsanitize=thread #-fsanitize=address  

SRCS = srcs/philo.c srcs/checker.c \
		srcs/utils.c srcs/main.c \
		srcs/init.c srcs/monitor.c \
		srcs/actions.c

$(NAME):
		cc $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

debug: 
	cc $(FLAGS) -fsanitize=thread $(SRCS) -o $(NAME)_debug
clean:
		rm -rf $(NAME)

fclean: clean
		rm -rf $(NAME)

re: fclean all
