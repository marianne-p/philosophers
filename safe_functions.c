#include "philo.h"

/*allocates, checks return, frees table on error */

void	*safe_malloc(size_t bytes, t_table *table)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit_free("Malloc error\n", 1, table);
	return (ret);
}

void	handle_mtx_err(int status, t_opcode opcode, t_table *table)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		error_exit_free("The mutex value is not valid\n", table);
	else if (status == EINVAL && opcode == INIT)
		error_exit_free("The attr value is invalid\n", 1, table);
	else if (status == EDEADLK)
		error_exit_free("A deadlock will occur if the thread is blocked waiting for mtx\n", 1, table);
	else if (status == EPERM)
		error_exit_free("Current thread doesn't hold a lock on mutex\n");
	else if (status == ENOMEM)
		error_exit_free("The process can't alloc enough memory for mtx creation\n");
	else if (status == EBUSY)
		error_exit_free("Mutex is locked");
}

void	handle_thrd_err(int status, t_opcode opcode, t_table *table)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit_free("No resources for extra thread\n", 1, table);
	else if (status == EPERM)
		error_exit_free("The caller doesn't have the permission\n", 1, table);
	else if (status == EINVAL && opcode == CREATE)
		error_exit_free("The value of attr is invalid\n", 1, table);
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_exit_free("The value specified is not joinable\n", 1, table);
	else if (status == ESRCH)
		error_exit_free("No thread couble be found corresponding to the one"
		"specified by the given thread ID, thread", 1, table);
	else if (status == EDEADLK)
		error_exit_free("A deadlock was detected\n", 1, table);
}

/*
void	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		error_exit("Wrong opcode for mutex handle\n", 1);
}*/
