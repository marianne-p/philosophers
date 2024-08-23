#include "philo.h"

void	*simulation(void *ptr)
{
	t_philo *philo;

	philo = (t_table *)ptr;
	if (pthread_mutex_lock(philo->left_fork->fork) == 0 &&
			pthread_mutex_lock(philo->right_fork->fork) == 0)
		eating(philo);
	pthread_mutex_unlock(philo->left_fork->fork);
	pthread_mutex_unlock(philo->right_fork->fork);
	/*sleep after the food*/
	/*think if not eating and not sleeping*/
}

void	eating(t_philo *philo)
{
	/*how to access time_to_eat from the table
	 OR
	 how to access the correct philo for the thread?*/
}

void	sleeping(t_philo *philo, t_table *table)
{

}

/*Thinking will switch on when Philo is unable to start eating*/
void	thinking(t_philo *philo)
{

}