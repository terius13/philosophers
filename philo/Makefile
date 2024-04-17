# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:22:30 by ting              #+#    #+#              #
#    Updated: 2024/04/17 17:57:43 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra -g -pthread

SRCS = srcs/checker.c \

$(NAME):
		cc $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(NAME)

fclean: clean
		rm -rf $(NAME)

re: fclean all