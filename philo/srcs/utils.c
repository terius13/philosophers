/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:35:56 by ting              #+#    #+#             */
/*   Updated: 2024/04/18 17:39:10 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *str)
{
	printf(R"%s\n"RET, str);
	exit(1);
}

u_int64_t   get_time(void)
{
    struct timeval   time;

    if (gettimeofday(&time, NULL) != 0)
    {
        ft_error("gettimeofday Error");
    }
    return((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}