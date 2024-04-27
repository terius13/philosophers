/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:06:48 by ting              #+#    #+#             */
/*   Updated: 2024/04/27 17:03:28 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_table table;
    long   time;

    if (init_input(&table, argc, argv) == 1)
        return (1);
    time = get_time();
    printf("%ld\n", time);
	if (create_philos(&table) == 1)
        return (1);
}
