/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:35:56 by ting              #+#    #+#             */
/*   Updated: 2024/04/29 19:22:25 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long   get_time(void)
{
    struct timeval   time;

    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void    ft_usleep(long ms)
{
    long    time;

    time = get_time();
    while (get_time() - time < ms)
        usleep(ms / 10);
}

void    free_all(t_table *table)
{
    int i;
    
    i = table->num_of_philos - 1;
    while (i >= 0)
    {
        pthread_mutex_destroy(&table->forks[i]);
        pthread_mutex_destroy(&table->philos[i].eat_lock);
        i--;
    }
    pthread_mutex_destroy(&table->message_lock);
    free(table->philos);
    free(table->forks);
}