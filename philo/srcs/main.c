/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:06:48 by ting              #+#    #+#             */
/*   Updated: 2024/05/07 19:38:27 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (init_all(&table, argc, argv) == 1)
	{
		return (1);
	}
	if (create_philos_and_join(&table) == 1)
		return (1);
	free_all(&table);
}
