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

void	init(t_table *table)
{
	i = 0;
	table->end_simulation = false;
	table->philos = safe_malloc(sizeof(t_philo *) * table->philo_nbr, table);
	table->forks = safe_malloc(sizeof(t_fork *) * table->philo_nbr, table);
	while (i < table->philo_nbr)
	{
		table->philos[i]->id = i + 1;
		table->philos[i]->meals_counter = 0;
		table->philos[i]->full = false;
		//table->philos[i]->last_meal_time = 
		table->philos
	}
}
