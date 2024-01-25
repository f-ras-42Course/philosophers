/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 19:18:25 by fras          #+#    #+#                 */
/*   Updated: 2024/01/25 20:55:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_mutex(t_mutex_group *mutex)
{
	int	i;

	i = -1;
	while (++i < 200)
		if (pthread_mutex_init(&mutex->fork[i], NULL))
			return (destroy_fork_mutex(mutex->fork, i), false);
	if (pthread_mutex_init(&mutex->print, NULL))
		return (destroy_fork_mutex(mutex->fork, 200), false);
	if (pthread_mutex_init(&mutex->eat, NULL))
	{
		destroy_fork_mutex(mutex->fork, 200);
		pthread_mutex_destroy(&mutex->print);
		return (false);
	}
	if (pthread_mutex_init(&mutex->finish, NULL))
	{
		destroy_fork_mutex(mutex->fork, 200);
		pthread_mutex_destroy(&mutex->print);
		pthread_mutex_destroy(&mutex->eat);
		return (false);
	}
	return (true);
}


void	destroy_fork_mutex(pthread_mutex_t *forks, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
		pthread_mutex_destroy(&forks[i]);
}

void	destroy_mutex(t_mutex_group *mutex)
{
	int	i;

	i = -1;
	while (++i < 200)
		pthread_mutex_destroy(&mutex->fork[i]);
	pthread_mutex_destroy(&mutex->print);
	pthread_mutex_destroy(&mutex->eat);
	pthread_mutex_destroy(&mutex->finish);
}
