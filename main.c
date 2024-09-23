/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:36:45 by mpihur            #+#    #+#             */
/*   Updated: 2024/08/20 16:12:35 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(char *str, int r)
{
	write(2, str, ft_strlen(str));
	exit(r);
}

/*Is ft_atoi cheching for non-num values?*/

bool	check_is_int(int argc, char **argv, int i)
{
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || ft_atoi(argv[i]) > INT_MAX
				|| ft_atoi(argv[i]) < 0)
			return (false);
		i++;
	}
	return (true);
}

void	parse_philo(int argc, char **argv, t_table *table)
{
	table->philo_nbr = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]) * 1000;
	table->time_to_eat = ft_atoi(av[3]) * 1000;
	table->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (table->time_to_die < 6000 || table->time_to_eat < 60000
			|| table->time_to_sleep < 60000)
			error_exit("Time argument/s invalid (less than 60ms)\n", 1);
	if (argc == 6)
		table->nbr_limit_meals = ft_atoi(av[5]);
	else
		table->nbr_limit_meals = -1;
}

int	main(int argc, char **argv, char **envv)
{
	t_table	table;

	//table = (t_table)NULL;
	if (argc != 5 && argc != 6)
		error_exit("Wrong Argument Number\n", 1);
	if (check_is_int(argc, argv, 1) != true)
		error_exit("Arguments are not integers\n", 1);
	parse_philo(argc, argv, &table);
	init(&table, 0);
	run_philo(&table);
	clean(&table);
	return (0);
}
