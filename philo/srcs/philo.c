/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:51 by ting              #+#    #+#             */
/*   Updated: 2024/05/05 22:28:36 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Each thread is a philo

//This function is needed to mutex_lock when checking end_simulations, as its reading it. 
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

int	check_end_simul_2(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meal_count < philo->table->num_of_meals || philo->table->num_of_meals == -1)
		return (pthread_mutex_unlock(philo->meal_lock), 0);
	pthread_mutex_unlock(philo->meal_lock);
	return (1);
}

void	*do_routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
//	printf("philo thread %i is running\n", philo->id);//rm later, will cause helgrind error
	
	if (philo->id % 2 == 0)
		{
			ft_usleep(1);
		}
	
//reading meal_count might give me data race, can add into check_end_simu
	while (check_end_simulation(philo) == 0 && check_end_simul_2(philo) == 0) 
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
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
		if (pthread_create(&(philo[i].thread_id), NULL, do_routine, (void *)&philo[i]) != 0)
			return (write(2, "Error creating thread\n", 23), 1);
		i++;
	}
	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_join(philo[i].thread_id, NULL);
	//	printf(G "philo thread %d joined\n" RST, philo[i].id);//rm later, will cause helgrind error
		i++;
	}
	pthread_join(monitor_t, NULL);
	return (0);
}
