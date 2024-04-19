/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:51 by ting              #+#    #+#             */
/*   Updated: 2024/04/20 00:00:11 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//Each thread is a philo
//I need to create the number of thread base on the input that specifies the num of philo.

void	*thread_function(void *arg)
{
	int	id;

	id = *((int *) arg);
	printf("philo thread %i is running\n", id);
	return (NULL);
}

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
		philo_id[i] = i;
		result = pthread_create(&philo[j], NULL, thread_function, (void *)&philo_id[i]);
		if (result != 0)
		{
			printf("Error creating threads %d\n" , i);
		}
		i++;
		j++;
	}
	i = 1;
	j = 0;
	while (i <= ft_atol(argv[1]))
	{
		pthread_join(philo[j], NULL);
		printf("philo thread %d joined\n", philo_id[i]);
		i++;
		j++;
	}
}
