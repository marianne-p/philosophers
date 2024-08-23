/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:37:50 by mpihur            #+#    #+#             */
/*   Updated: 2024/08/20 16:12:13 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <stdbool.h>

enum e_optcode {
	LOCK = 1,
	UNLOCK = 2,
	INIT = 3,
	DESTROY = 4
} t_opcode;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	long	end_simulation;
	t_fork	**forks;
	t_philo	**philos;
}	t_table;

/*libft.c*/
size_t		ft_strlen(const char *str);
long long	ft_atoi(const char *nptr);

/*main.c*/
bool	check_is_int(int argc, char **argv, int i);
void	error_exit(char *str, int r);
void	parse_philo(int argc, char **argv, t_table *table);

#endif
