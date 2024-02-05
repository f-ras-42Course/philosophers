/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 19:18:25 by fras          #+#    #+#                 */
/*   Updated: 2024/02/05 19:41:43 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_mutex_group *mutex, int fork_amount)
{
	int	i;

	i = -1;
	mutex->fork = malloc(fork_amount * sizeof(pthread_mutex_t));
	if (!mutex->fork)
		return (print_error(MALLOC_FAILED_MUTEX));
	while (++i < fork_amount)
		if (pthread_mutex_init(&mutex->fork[i], NULL))
			return (destroy_mutex(mutex, fork_amount, 1), \
					print_error(MUTEX_FAILED));
	if (pthread_mutex_init(&mutex->print, NULL))
		return (destroy_mutex(mutex, fork_amount, 1), \
				print_error(MUTEX_FAILED));
	if (pthread_mutex_init(&mutex->eat, NULL))
		return (destroy_mutex(mutex, fork_amount, 2), \
				print_error(MUTEX_FAILED));
	if (pthread_mutex_init(&mutex->start, NULL))
		return (destroy_mutex(mutex, fork_amount, 3), \
				print_error(MUTEX_FAILED));
	if (pthread_mutex_init(&mutex->finish, NULL))
		return (destroy_mutex(mutex, fork_amount, 4), \
				print_error(MUTEX_FAILED));
	return (0);
}

void	destroy_mutex(t_mutex_group *mutex, int fork_amount, int mutex_amount)
{
	int	i;

	i = -1;
	if (mutex_amount >= 1)
		while (++i < fork_amount)
			pthread_mutex_destroy(&mutex->fork[i]);
	if (mutex_amount >= 2)
		pthread_mutex_destroy(&mutex->print);
	if (mutex_amount >= 3)
		pthread_mutex_destroy(&mutex->eat);
	if (mutex_amount >= 4)
		pthread_mutex_destroy(&mutex->start);
	if (mutex_amount >= 5)
		pthread_mutex_destroy(&mutex->finish);
}
