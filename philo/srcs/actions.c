/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:39:12 by ting              #+#    #+#             */
/*   Updated: 2024/05/05 19:50:40 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	else if (type == 8)
		printf(R "%ld %i died\n" RST, get_time() - philo->table->start_time, philo->id);
	pthread_mutex_unlock(&philo->table->message_lock);
}

//When a philo is done sleeping, it will think for 1ms
//This helps stagger philosopher's eating routines to avoid forks
//being monopolized by one philosopher to the detriment of others.
void	thinking(t_philo *philo)
{
	message(philo, 2);
	ft_usleep(1);
}

void	sleeping(t_philo *philo)
{
	message(philo, 3);
	ft_usleep(philo->table->time_to_sleep);
}

//Even philo picks up left fork first
//Odd philo picks up right fork first
void    take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		message(philo, 4);
		pthread_mutex_lock(philo->l_fork);
		message(philo, 5);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		message(philo, 5);
		pthread_mutex_lock(philo->r_fork);
		message(philo, 4);
	}
	/*
	pthread_mutex_lock(philo->r_fork);
	message(philo, 4);
	pthread_mutex_lock(philo->l_fork);
	message(philo, 5);
	*/
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	message(philo, 1);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_lock);

	if (philo->id % 2 == 0)
	{
		message(philo, 7);
		pthread_mutex_unlock(philo->l_fork);
		message(philo, 6);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		message(philo, 6);
		pthread_mutex_unlock(philo->r_fork);
		message(philo, 7);
		pthread_mutex_unlock(philo->l_fork);
	}
}