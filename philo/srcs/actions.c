/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:39:12 by ting              #+#    #+#             */
/*   Updated: 2024/05/07 19:33:15 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// All actions funcion check end_simu first,
// to stop other thread from continueing,
// in the case where a philo dies, else it will print "philo died",
// but still continue to print other threads's action e.g sleeping,take forks.

// Type 1 is for eating, Type 2 is for thinking, Type 3 is for sleeping
// Type 4 is for taken a fork, Type 5 is when a philo dies.
void	message(t_philo *philo, int type)
{
	if (check_end_simulation(philo) == 1)
		return ;
	pthread_mutex_lock(philo->message_lock);
	if (type == 1)
		printf(Y "%ld %i is eating\n" RST, get_time()
			- philo->table->start_time, philo->id);
	else if (type == 2)
		printf(C "%ld %i is thinking\n" RST, get_time()
			- philo->table->start_time, philo->id);
	else if (type == 3)
		printf(M "%ld %i is sleeping\n" RST, get_time()
			- philo->table->start_time, philo->id);
	else if (type == 4)
		printf(B "%ld %i has taken a fork\n" RST, get_time()
			- philo->table->start_time, philo->id);
	else if (type == 5)
		printf(R "%ld %i died\n" RST, get_time() - philo->table->start_time,
			philo->id);
	pthread_mutex_unlock(philo->message_lock);
}

// When a philo is done sleeping, it will think for 1ms
// This helps stagger philosopher's eating routines to avoid forks
// being monopolized by one philosopher to the detriment of others.
void	thinking(t_philo *philo)
{
	if (check_end_simulation(philo) == 1)
		return ;
	message(philo, 2);
	ft_usleep(1);
}

void	sleeping(t_philo *philo)
{
	if (check_end_simulation(philo) == 1)
		return ;
	message(philo, 3);
	ft_usleep(philo->table->time_to_sleep);
}

// Even philo picks up right fork first
// Odd philo picks up left fork first
// To prevent data races
void	take_forks(t_philo *philo)
{
	if (check_end_simulation(philo) == 1)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		message(philo, 4);
		pthread_mutex_lock(philo->l_fork);
		message(philo, 4);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		message(philo, 4);
		pthread_mutex_lock(philo->r_fork);
		message(philo, 4);
	}
}

void	eating(t_philo *philo)
{
	if (check_end_simulation(philo) == 1)
		return ;
	take_forks(philo);
	message(philo, 1);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_lock);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}
//Fork mutex are unlocked in the opp of how it was locked to prevent datarace