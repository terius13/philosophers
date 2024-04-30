/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:51 by ting              #+#    #+#             */
/*   Updated: 2024/04/30 22:05:19 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Each thread is a philo
//I need to create the number of thread base on the input that specifies the num of philo.

//type 1 is for eating, type 2 is for thinking, type 3 is for sleeping
//type 4 is picked up r_fork, type 5 is picked up l_fork
//type 6 is dropped r_fork, type 7 is dropped l_fork
void	message(t_philo *philo, int type)
{
	pthread_mutex_lock(&philo->table->message_lock);
	if (type == 1)
		printf(Y "%ld %i is eating\n" RST, get_time() - philo->table->start_time, philo->id);
	else if (type == 2)
		printf(C "%ld %i is thinking\n" RST, get_time() - philo->table->start_time, philo->id);
	else if (type == 3)
		printf(M "%ld %i is sleeping\n" RST, get_time() - philo->table->start_time, philo->id);
	else if (type == 4)
		printf(B "%ld %i picked up the r_fork\n" RST, get_time() - philo->table->start_time, philo->id);
	else if (type == 5)
		printf(B "%ld %i picked up the l_fork\n" RST, get_time() - philo->table->start_time, philo->id);
	else if (type == 6)
		printf(R "%ld %i dropped the r_fork\n" RST, get_time() - philo->table->start_time, philo->id);
	else if (type == 7)
		printf(R "%ld %i dropped the l_fork\n" RST, get_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->message_lock);
}

void	thinking(t_philo *philo)
{
	message(philo, 2);
}

void	sleeping(t_philo *philo)
{
	message(philo, 3);
	ft_usleep(philo->table->time_to_sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_lock);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		message(philo, 5);
		pthread_mutex_lock(philo->r_fork);
		message(philo, 4);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		message(philo, 4);
		pthread_mutex_lock(philo->l_fork);
		message(philo, 5);
	}
//	pthread_mutex_lock(&philo->eat_lock);
//	pthread_mutex_lock(philo->r_fork);
//	message(philo, 4);
//	pthread_mutex_lock(philo->l_fork);
//	message(philo, 5);
	message(philo, 1);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->eat_lock);
	ft_usleep(philo->table->time_to_eat);
	message(philo, 7);
	pthread_mutex_unlock(philo->l_fork);
	message(philo, 6);
	pthread_mutex_unlock(philo->r_fork);
}

void	*do_routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	printf("philo thread %i is running\n", philo->id);
	/*
	if (philo.id % 2 == 0)
		{
			ft_usleep(1);
		}
	*/
	while (philo->table->end_simulation == 0) 
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

int	create_philos_and_join(t_table *table)
{
	int	i;
	pthread_t	monitor_t;
	t_philo	*philo;

	i = 0;
	philo = table->philos;
	table->start_time = get_time();
	
	if (pthread_create(&monitor_t, NULL, &monitor, (void *)table) != 0)
		return (write(2, "Error creating thread\n", 22), 1);
	while (i < table->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].table = table;
		if (pthread_create(&(philo[i].thread_id), NULL, do_routine, (void *)&philo[i]) != 0)
			return (write(2, "Error creating thread\n", 23), 1);
		i++;
	}
	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_join(philo[i].thread_id, NULL);
		printf(G "philo thread %d joined\n" RST, philo[i].id);
		i++;
	}
	pthread_join(monitor_t, NULL);
	return (0);
}
