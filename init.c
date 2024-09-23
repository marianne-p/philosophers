/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:12:50 by mpihur            #+#    #+#             */
/*   Updated: 2024/08/20 16:15:42 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*`void * (*start_routine)` pointer to function which takes `void *`
*/

void	init(t_table *table, int i)
{
	i = 0;
	table->end_simulation = false;
	table->philos = safe_malloc(table->philo_nbr * sizeof(t_philo));
	table->forks = safe_malloc(table->philo_nbr * sizeof(t_fork));
	while ((table->forks)[i])
	{
		(table->forks)[i]->fork_id = i;
		handle_mtx_err(pthread_mutex_init((table->forks)[i++]->fork, NULL), INIT, table);
	}
	i = -1;
	while ((table->philos)[++i])
	{
		(table->philos)[i]->id = i + 1;
		(table->philos)[i]->meals_counter = 0;
		(table->philos)[i]->full = false;
		(table->philos)[i]->table = table;
		(table->philos)[i]->left_fork = &(table->forks)[(i + 1) % table->philo_nbr];
		(table->philos)[i]->right_fork = &(table->forks)[i];
		if (i == 0)
			(table->philos)[i]->right_fork = table->philo_nbr;
		pthread_create((table->philos)[i]->thread_id, NULL, *simulation, (void *)(table->philos)[i]);
	}
}
