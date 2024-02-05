/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   status.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 15:35:25 by fras          #+#    #+#                 */
/*   Updated: 2024/02/05 15:04:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	print_status(t_philo *philo, t_philo_status what, \
				t_mutex_group mutex)
{
	if (is_finished(philo->general, false) && what != DIED)
		return (0);
	pthread_mutex_lock(&mutex.print);
	printf("%lu %d %s\n", get_time(), philo->id, doing(what));
	pthread_mutex_unlock(&mutex.print);
	return (get_time());
}

char	*doing(t_philo_status what)
{
	if (what == TAKING_FORK)
		return ("has taken a fork");
	if (what == EATING)
		return ("is eating");
	if (what == SLEEPING)
		return ("is sleeping");
	if (what == THINKING)
		return ("is thinking");
	return ("died");
}
