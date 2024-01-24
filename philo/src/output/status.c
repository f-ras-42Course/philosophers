/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   status.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 15:35:25 by fras          #+#    #+#                 */
/*   Updated: 2024/01/24 17:37:06 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(uint8_t id, t_philo_status what)
{
	static uint64_t	start_time;
	static bool		start_set;

	if (!start_set)
	{
		start_time = get_time();
		start_set = true;
	}
	printf("%ld ms %d %s\n", get_time() - start_time, id, doing(what));
}

char	*doing(t_philo_status what)
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
