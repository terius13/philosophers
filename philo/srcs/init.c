/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:45:43 by ting              #+#    #+#             */
/*   Updated: 2024/05/06 17:36:07 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_input(t_table *table, int argc, char **argv)
{
	if (ft_checker(argc, argv) == 1)
		return (1);
	table->num_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->end_simulation = 0;
	table->philos_done_eating = 0;
	if (argv[5])
		table->num_of_meals = ft_atol(argv[5]);
	else
		table->num_of_meals = -1;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philos);
	pthread_mutex_init(&table->message_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	return (0);
}

//init forks first before init philo.table
void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->num_of_philos);
	while (i < table->num_of_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

//init fork first then philo
void	init_philo(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = table->philos;
	while (i < table->num_of_philos)
	{
	//	philo[i].id = i + 1;
		philo[i].table = table;
		philo[i].meal_count = 0; 
		philo[i].finish_eating = 0;
		philo[i].id = i + 1;
		philo[i].r_fork = &table->forks[philo[i].id - 1];
		philo[i].l_fork = &table->forks[philo[i].id  % table->num_of_philos];
		philo[i].last_meal = get_time();
		// philo[i].message_lock = &table->meal_lock;
		philo[i].meal_lock = &table->meal_lock;
		philo[i].dead_lock = &table->dead_lock;
		i++;
	}
}

int    init_all(t_table *table, int argc, char **argv)
{
    if (init_input(table, argc, argv) == 1)
        return (1);
    init_forks(table);
    init_philo(table);
    return (0);
}