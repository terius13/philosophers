/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:06:48 by ting              #+#    #+#             */
/*   Updated: 2024/04/26 18:15:52 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_table table;
    long   time;

    init_input(&table, argc, argv);
    time = get_time();
    printf("%ld\n", time);
	init_philos(&table);
	//create_philos(argv);
}
