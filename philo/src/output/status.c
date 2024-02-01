/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   status.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 15:35:25 by fras          #+#    #+#                 */
/*   Updated: 2024/01/31 17:48:33 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	print_status(uint8_t id, t_philo_status what, t_mutex_group mutex)
{
	static uint64_t	start_time;
	static bool		start_set;

	pthread_mutex_lock(&mutex.print);
	if (!start_set)
	{
		start_time = get_time();
		start_set = true;
	}
	printf("%llu ms %d %s\n", get_time() - start_time, id, doing(what));
	pthread_mutex_unlock(&mutex.print);
	return (get_time() - start_time);
}

char		*doing(t_philo_status what)
{
	if (what == TAKING_FORK)
		return ("has taken a fork");
	if (what == EATING)
		return ("eating");
	if (what == SLEEPING)
		return ("is sleeping");
	if (what == THINKING)
		return ("is thinking");
	return ("died");
}
