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

void	init(t_cafe *cafe, int i)
{
	cafe->end_simulation = false;
	cafe->philos = safe_malloc(cafe->philo_nbr * sizeof(t_philo), cafe);
	cafe->straws = safe_malloc(cafe->philo_nbr * sizeof(t_straw), cafe);
	while ((cafe->straws)[i])
	{
		(cafe->straws)[i]->straw_id = i;
		handle_mtx_err(pthread_mutex_init((cafe->straws)[i++]->straw, NULL), INIT, cafe);
	}
	i = -1;
	while ((cafe->philos)[++i])
	{
		(cafe->philos)[i]->id = i + 1;
		(cafe->philos)[i]->drinks_counter = 0;
		(cafe->philos)[i]->full = false;
		(cafe->philos)[i]->cafe = cafe;
		(cafe->philos)[i]->left_straw = &(cafe->straws)[(i + 1) % cafe->philo_nbr];
		(cafe->philos)[i]->right_straw = &(cafe->straws)[i];
		if (i == 0)
			(cafe->philos)[i]->right_straw = cafe->philo_nbr;
		pthread_create((cafe->philos)[i]->thread_id, NULL, *simulation, (void *)(cafe->philos)[i]);
	}
	cafe->print_mutex = safe_mutex_handle(NULL, INIT);
}
