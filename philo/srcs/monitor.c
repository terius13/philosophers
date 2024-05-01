/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:45:25 by ting              #+#    #+#             */
/*   Updated: 2024/05/01 19:05:03 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//int   philos_are_dead()

//smth is not working they are eating more than expected
//maybe try changing the meal lock back to the main one
int   philos_all_ate(t_table *table)
{
    int i;
    t_philo *philo;

    i = 0;
    philo = table->philos;
    if (table->num_of_meals == -1)
        return (0);
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
/*  if (table->num_of_meals > 0)
    {
        while (1)
            if (philos_are_dead == 1 || philos_all_ate == 1)
                break;
    }
    else
    {
        while (1)
            if (philos_are_dead == 1)
                break;
    }
*/
        while (1)
        {
            if (philos_all_ate(table) == 1)
               break ;
        }
            return (NULL);
}
