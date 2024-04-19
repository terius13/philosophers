/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:23:37 by ting              #+#    #+#             */
/*   Updated: 2024/04/19 17:03:00 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <pthread.h>

// checker input error msg
# define ARG_ERROR_1 "Error: Argument is not digit / less than 1"
# define ARG_ERROR_2 "Error: Number of Philosopher exceeds 200"
# define ARG_ERROR_3 "Error: Incorrect number of arguments"

// checker.c
void	ft_argisdigit(char *arg);
long    ft_atol(const char *nptr);
int		ft_checker(int argc, char **argv);

//utils.c
void	ft_error(char *str);
u_int64_t   get_time(void);

//philo.c
void	*thread_function(void *arg);
void	create_philos(char **argv);

#endif
