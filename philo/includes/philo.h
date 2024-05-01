/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:37 by ting              #+#    #+#             */
/*   Updated: 2024/05/01 17:21:41 by ting             ###   ########.fr       */
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
# define Y "\033[33m"
# define C "\033[36m"
# define M "\033[35m"

typedef struct	s_philo
{
	pthread_t	thread_id;
	int	id;
	int	meal_count;
	int	finish_eating;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t *l_fork; //this is for l_fork[i]
	pthread_mutex_t *meal_lock;
	pthread_mutex_t *dead_lock;
	struct s_table	*table;
}				t_philo;

typedef struct	s_table
{
	long	num_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_of_meals;
	int		philos_done_eating;
	long	start_time;
	int	end_simulation; //1 or 0, 1 if dies, 0 if not
	t_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message_lock;
	pthread_mutex_t dead_lock;
	pthread_mutex_t	meal_lock;
}				t_table;

//init.c
int	init_input(t_table *table, int argc, char **argv);
void	init_forks(t_table *table);
void	init_philo(t_table *table);
int	init_all(t_table *table, int argc, char **argv);

// checker.c
int	ft_argisdigit(char *arg);
long    ft_atol(const char *nptr);
int		ft_checker(int argc, char **argv);

//utils.c
long   get_time(void);
void	ft_usleep(long ms);
void	free_all(t_table *table);

//philo.c
void	*do_routine(void *philo_pointer);
int	create_philos_and_join(t_table *table);

//monitor.c
int   philos_all_ate(t_table *table);
void    *monitor(void *table_ptr);

#endif
