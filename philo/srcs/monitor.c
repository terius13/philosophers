/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:45:25 by ting              #+#    #+#             */
/*   Updated: 2024/05/06 18:08:43 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//a loop thru all the philos to check their last meal against time_to_die
int   philos_are_dead(t_table *table)
{
    int i;
    int dead_flag;
    t_philo *philo;

    i = 0;
    dead_flag = 0;
    philo = table->philos;
    while (i < table->num_of_philos)
    {
        pthread_mutex_lock(&table->meal_lock);
        if ((get_time() - philo[i].last_meal) > table->time_to_die && philo[i].meal_count != table->num_of_meals)
        {
            dead_flag = 1;
        //    message(&philo[i], 8);
        }
        pthread_mutex_unlock(&table->meal_lock);
        if (dead_flag == 1)
        {
            message(&philo[i], 8);
            pthread_mutex_lock(&table->dead_lock);
            table->end_simulation = 1;
            pthread_mutex_unlock(&table->dead_lock);
            return (1);
        }
        i++;
    }
    
    return (0);
}
//need a condition if philo is done eating he drops out and not continue eating
//can use finish_eating as a condition but need to make it global in struct
int   philos_all_ate(t_table *table)
{
    int i;
    t_philo *philo;

    i = 0;
    philo = table->philos;
    while (i < table->num_of_philos)
    {
        pthread_mutex_lock(&table->meal_lock);
        if (philo[i].meal_count >= table->num_of_meals && philo[i].finish_eating != 1)
        {
            philo[i].finish_eating = 1;
            table->philos_done_eating++;
        }
        pthread_mutex_unlock(&table->meal_lock);
        i++;
    }
    if (table->philos_done_eating == table->num_of_philos)
    {
        pthread_mutex_lock(&table->dead_lock);
        table->end_simulation = 1;
        pthread_mutex_unlock(&table->dead_lock);
        return (1);
    }
    return (0);
}

void    *monitor(void *table_ptr)
{
    t_table *table;
    
    table = (t_table *)table_ptr;
    if (table->num_of_meals > 0)
    {
        while (1)
            if (philos_are_dead(table) == 1 || philos_all_ate(table) == 1)
            {
                break;
            }
    }
    else
    {
        while (1)
            if (philos_are_dead(table) == 1)
                break;
    }
/*
        while (1)
        {
            if (philos_all_ate(table) == 1)
               break ;
        }
        */
            return (NULL);
}
