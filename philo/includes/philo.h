/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:37 by ting              #+#    #+#             */
/*   Updated: 2024/04/27 23:02:07 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

# define RST "\033[0m"
# define R "\033[1;31m"
# define G "\033[32m"
# define B "\033[34m"

typedef struct	s_philo
{
	pthread_t	thread_id;
	int	id;
	int	meal_count;
	pthread_mutex_t	*r_fork; //might need to change to int depending on how i want to handle this
	pthread_mutex_t *l_fork; //this is for l_fork[i]
	struct s_table	*table;
}				t_philo;

typedef struct	s_table
{
	long	num_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_of_meals;
	long	start_time;
	bool	end_simulation;
	t_philo	*philos;
	pthread_mutex_t	*forks;
}				t_table;

// checker.c
int	ft_argisdigit(char *arg);
long    ft_atol(const char *nptr);
int		ft_checker(int argc, char **argv);

//utils.c
void	error_exit(char *str);
long   get_time(void);
void	ft_usleep(long ms);

//philo.c
void	*do_routine(void *philo_pointer);
int	init_input(t_table *table, int argc, char **argv);
int	create_philos(t_table *table);

#endif
