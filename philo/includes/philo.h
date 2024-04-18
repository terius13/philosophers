/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:37 by ting              #+#    #+#             */
/*   Updated: 2024/04/18 17:39:03 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>

// define colours
# define RET "\033[0m"
# define R "\033[1;31m"

// checker input error msg
# define ARG_ERROR_1 "Error: Argument is not digit / less than 1"
# define ARG_ERROR_2 "Error: Number of Philosopher exceeds 200"
# define ARG_ERROR_3 "Error: Incorrect number of arguments"

// checker.c
void	ft_argisdigit(char *arg);
int		ft_pos_atoi(char *str);
int		ft_checker(int argc, char **argv);

//utils.c
void	ft_error(char *str);
u_int64_t   get_time(void);

#endif