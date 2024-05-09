# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:22:30 by ting              #+#    #+#              #
#    Updated: 2024/05/08 16:30:20 by ting             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra -g -lpthread -fsanitize=thread #-fsanitize=address  

SRCS_PATH = srcs/

SRCS = philo.c checker.c \
		utils.c main.c \
		init.c monitor.c \
		actions.c

OBJS = $(addprefix $(SRCS_PATH), $(SRCS:.c=.o))

$(NAME): $(OBJS)
		cc $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
