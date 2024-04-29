
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:11:45 by ting              #+#    #+#             */
/*   Updated: 2024/04/26 18:15:51 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// the checker should check the input to make sure that it is all numerical
//[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat(optional)]
// 5 800 200 250 7
// 5 — The number of philosophers (not more than 200)
// 800 — The time a philosopher will die if he doesn’t eat (more than 0)
// 200 — The time it takes a philosopher to eat (more than 0)
// 250 — The time it takes a philosopher to sleep (more than 0)
// 7 — Number of times all the philosophers need to eat before terminating the program (optional)

void	error_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	ft_argisdigit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

long    ft_atol(const char *nptr)
{
        long    neg;
        int             i;
        long    num;

        i = 0;
        neg = 1;
        num = 0;
        while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
                i++;
        if (nptr[i] == '-' || nptr[i] == '+')
        {
                if (nptr[i] == '-')
                        neg = neg * -1;
                i++;
        }
        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
                num = num * 10 + (nptr[i] - '0');
                i++;
        }
        return (num * neg);
}

int	ft_checker(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 5 || argc == 6) 
	{
		while (i < argc)
		{
			if (ft_argisdigit(argv[i]) == 1)
				return (write(2, "Argument is not digit / less than 1\n", 37), 1);
			i++;
		}
		if (ft_atol(argv[1]) > 200)
			return (write(2, "Philo count exceeds 200\n", 25), 1);
		if (ft_atol(argv[1]) <= 0 || ft_atol(argv[2]) <= 0
			|| ft_atol(argv[3]) <= 0 || ft_atol(argv[4]) <= 0)
			return (write(2, "Argument is less than 1\n", 25), 1);
		if (argv[5])
			if (ft_atol(argv[5]) <= 0)
				return (write(2, "Argument is less than 1\n", 25), 1);
	}
	else			
		return (write(2, "Incorrect number of arguments\n", 31), 1);
	return (0);
}
