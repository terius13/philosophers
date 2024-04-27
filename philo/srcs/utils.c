/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:35:56 by ting              #+#    #+#             */
/*   Updated: 2024/04/27 18:49:13 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

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