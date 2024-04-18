# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:22:30 by ting              #+#    #+#              #
#    Updated: 2024/04/18 15:47:04 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra -g -pthread

SRCS = srcs/philo.c srcs/checker.c \
		srcs/utils.c

$(NAME):
		cc $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(NAME)

fclean: clean
		rm -rf $(NAME)

re: fclean all