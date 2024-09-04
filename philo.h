/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:37:50 by mpihur            #+#    #+#             */
/*   Updated: 2024/09/04 13:34:35 by mpihur           ###   ########.fr       */
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
#include <errno.h>

enum e_optcode {
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
} t_opcode;

typedef struct s_straw
{
	pthread_mutex_t	*straw;
	int				straw_id;
}	t_straw;

typedef struct s_philo
{
	int			id;
	long		drinks_counter;
	bool		full;
	long		last_drink_time;
	t_cafe		*cafe;
	t_straw		*left_straw;
	t_straw		*right_straw;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_cafe
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_drinks;
	long	start_simulation;
	long	end_simulation;
	t_straw	**straws;
	t_philo	**philos;
}	t_cafe;

/*libft.c*/
size_t		ft_strlen(const char *str);
long long	ft_atoi(const char *nptr);

/*main.c*/
bool	check_is_int(int argc, char **argv, int i);
void	error_exit(char *str, int r);
void	parse_philo(int argc, char **argv, t_cafe *table);

/*safe functions*/
void	*safe_malloc(size_t bytes, t_cafe *table);
void	handle_mtx_err(int status, t_opcode opcode, t_cafe *table);
void	handle_thrd_err(int status, t_opcode opcode, t_cafe *table);

#endif
