/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:35:56 by ting              #+#    #+#             */
/*   Updated: 2024/04/20 15:26:17 by ting             ###   ########.fr       */
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

    if (gettimeofday(&time, NULL) != 0)
    {
        ft_error("gettimeofday Error");
    }
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
