#include "philo.h"

void	*simulation(void *ptr)
{
	t_philo *philo;

	philo = (t_cafe *)ptr;
	if (pthread_mutex_lock(philo->left_straw->straw) == 0 &&
			pthread_mutex_lock(philo->right_straw->straw) == 0)
		eating(philo);
	pthread_mutex_unlock(philo->left_straw->straw);
	pthread_mutex_unlock(philo->right_straw->straw);
	/*sleep after the food*/
	/*think if not eating and not sleeping*/
}

void	eating(t_philo *philo)
{
	/*how to access time_to_eat from the cafe
	 OR
	 how to access the correct philo for the thread?*/
	philo->last_drink_time = get_current_time();
	while (get_current_time() - philo->last_drink_time < philo->cafe->time_to_eat)
		usleep(1);
	if (philo->last_drink_time - philo->cafe->start_simulation > philo->cafe->time_to_die)
	{
		/*Philosopher died*/
	}
	if (pthread_mutex_lock(philo->cafe->print_mutex) == 0)
		printf("%ld, %d is eating\n", get_current_time() - philo->cafe->start_simulation, philo->id);
	else
	{
		usleep(2);
		eating(philo);
	}
		philo->drinks_counter++;
}

void	sleeping(t_philo *philo, t_cafe *table)
{

}

/*Thinking will switch on when Philo is unable to start eating*/
void	thinking(t_philo *philo)
{

}