/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:11:45 by ting              #+#    #+#             */
/*   Updated: 2024/04/17 17:57:39 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//the checker should check the input to make sure that it is all numerical
//[number_of_philosophers] [time_to_die time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat(optional)]
//5 800 200 250 7
//5 — The number of philosophers (not more than 200)
//800 — The time a philosopher will die if he doesn’t eat (more than 0)
//200 — The time it takes a philosopher to eat (more than 0)
//250 — The time it takes a philosopher to sleep (more than 0)
//7 — Number of times all the philosophers need to eat before terminating the program (optional)

//returns 0 if not digit, 1 if arg is digit

void    ft_args_error(char *str)
{
    printf("%s\n", str);
    exit(1);
}    

void    ft_argisdigit(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            ft_args_error(ARG_ERROR_1);
        i++;
    }
}

int ft_pos_atoi(char *str)
{
    int num;
    int i;

    i = 0;
    num = 0;
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num);
}

int ft_checker(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc == 5 || argc == 6)
    {
        while (i < argc)
        {
            ft_argisdigit(argv[i]);
            i++;
        }
        if (ft_pos_atoi(argv[1]) > 200)
            ft_args_error(ARG_ERROR_3);
        if (ft_pos_atoi(argv[1]) <= 0 || ft_pos_atoi(argv[2]) <= 0
                || ft_pos_atoi(argv[3]) <= 0 || ft_pos_atoi(argv[4]) <= 0)
            ft_args_error(ARG_ERROR_2);
        if (argv[5])
            if(ft_pos_atoi(argv[5]) <= 0)
              ft_args_error(ARG_ERROR_2);
    }
    else
        ft_args_error(ARG_ERROR_4);
    return (0);
}

int main(int argc, char **argv)
{
    ft_checker(argc, argv);
}