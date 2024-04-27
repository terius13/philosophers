/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:51 by ting              #+#    #+#             */
/*   Updated: 2024/04/27 12:42:29 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Each thread is a philo
//I need to create the number of thread base on the input that specifies the num of philo.

void	*thread_function(void *arg)
{
	int	id;

	id = *((int *) arg);
	printf(B "philo thread %i is running\n" RST, id);
	return (NULL);
}

void	init_input(t_table *table, int argc, char **argv)
{
	ft_checker(argc, argv);
	table->num_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->num_of_meals = ft_atol(argv[5]);
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philos);
}
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
void	create_philos(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = table->philos;
	while (i < table->num_of_philos)
	{
		philo[i].id = i + 1;
		if (pthread_create(&(philo[i].thread_id), NULL, thread_function, (void *)&philo[i].id))
			error_exit(PTHREAD_ERR_1);
		i++;
	}
	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_join(philo[i].thread_id, NULL);
		printf(G "philo thread %d joined\n" RST, philo[i].id);
		i++;
	}
}
