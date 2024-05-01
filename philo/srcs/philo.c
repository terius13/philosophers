/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:51 by ting              #+#    #+#             */
/*   Updated: 2024/05/01 21:54:20 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Each thread is a philo
//I need to create the number of thread base on the input that specifies the num of philo.

int		check_end_simulation(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->table->end_simulation == 1)
	{
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*do_routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	printf("philo thread %i is running\n", philo->id);
	/*
	if (philo->id % 2 == 0)
		{
			ft_usleep(1);
		}
	*/
	while (check_end_simulation(philo) == 0 &&
				(philo->meal_count < philo->table->num_of_meals || philo->table->num_of_meals == -1)) 
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
