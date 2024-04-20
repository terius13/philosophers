/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:37 by ting              #+#    #+#             */
/*   Updated: 2024/04/20 15:26:46 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

// checker input error msg
# define ARG_ERROR_1 R "Error: Argument is not digit / less than 1" RST
# define ARG_ERROR_2 R "Error: Number of Philosopher exceeds 200" RST
# define ARG_ERROR_3 R "Error: Incorrect number of arguments" RST

# define RST "\033[0m"
# define R "\033[1;31m"
# define G "\033[32m"
# define B "\033[34m"

typedef struct	s_table
{
	long	num_of_philos;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	num_of_meals;
	long	start_time;
	bool	end_simulation;
}				t_table;

// checker.c
void	ft_argisdigit(char *arg);
long    ft_atol(const char *nptr);
int		ft_checker(int argc, char **argv);

//utils.c
void	ft_error(char *str);
long   get_time(void);

//philo.c
void	*thread_function(void *arg);
void	create_philos(char **argv);

#endif
