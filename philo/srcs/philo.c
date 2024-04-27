/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:51 by ting              #+#    #+#             */
/*   Updated: 2024/04/27 23:03:21 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Each thread is a philo
//I need to create the number of thread base on the input that specifies the num of philo.

void	thinking(t_philo philo)
{
	printf("%ld %i is thinking\n", get_time() - philo.table->start_time, philo.id);
}

void	sleeping(t_philo philo)
{
	printf("%ld %i is sleeping\n", get_time() - philo.table->start_time, philo.id);
	ft_usleep(philo.table->time_to_sleep);
}

//void	eating(t_philo philo)

void	*do_routine(void *philo_pointer)
{
	t_philo	philo;

	philo = *((t_philo *) philo_pointer);
	printf(B "philo thread %i is running\n" RST, philo.id);
	thinking(philo);
	sleeping(philo);
	return (NULL);
}

int	init_input(t_table *table, int argc, char **argv)
{
	if (ft_checker(argc, argv) == 1)
		return (1);
	table->num_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->num_of_meals = ft_atol(argv[5]);
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philos);
	return (0);
}

//void	init_forks()

/*
void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		//might need to change this
		table->philos[i].r_fork = table->philos[i].id;
		table->philos[i].l_fork = (table->philos[i].id + 1) % table->num_of_philos;
		i++;
	}
}
*/
int	create_philos(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = table->philos;
	table->start_time = get_time();
	while (i < table->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].table = table;
		if (pthread_create(&(philo[i].thread_id), NULL, do_routine, (void *)&philo[i]))
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
	return (0);
}
