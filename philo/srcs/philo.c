/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:51 by ting              #+#    #+#             */
/*   Updated: 2024/04/25 21:31:51 by ting             ###   ########.fr       */
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
	//int	i;

	//i = 0;
	ft_checker(argc, argv);
	table->num_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->num_of_meals = ft_atol(argv[5]);
}
/*
//create a new function but using the struct
void	create_philos()
{
}
*/
/*
void	create_philos(char **argv) //maybe i can do a pthread_t * , to return the array of threads, assign to my table struct
{
	pthread_t	philo[ft_atol(argv[1])];
	int	philo_id[ft_atol(argv[1])];
	int	result;
	int	i; //i could just use 1 variable if i change it to i + 1
	int	j;

	i = 1;
	j = 0;
	result = 0;
	while (i <= ft_atol(argv[1])) //might need to change to <=
	{
		philo_id[j] = i;
		result = pthread_create(&philo[j], NULL, thread_function, (void *)&philo_id[j]);
		if (result != 0)
		{
			printf(R "Error creating threads %d\n" RST, i);
		}
		i++;
		j++;
	}
	i = 1;
	j = 0;
	while (i <= ft_atol(argv[1]))
	{
		pthread_join(philo[j], NULL);
		printf(G "philo thread %d joined\n" RST, philo_id[j]);
		i++;
		j++;
	}
}
*/