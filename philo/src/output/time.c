/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 16:33:30 by fras          #+#    #+#                 */
/*   Updated: 2024/02/03 19:23:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	uint64_t		current_time;
	static uint64_t	start_time;
	static bool		start_set;
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (UINT64_MAX);
	current_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
	if (!start_set)
	{
		start_time = current_time;
		start_set = true;
	}
	return (current_time - start_time);
}

void	ms_sleep(t_general *general, uint64_t ms)
{
	uint64_t	start_time;

	start_time = get_time();
	while (!is_finished(general, false) && get_time() - start_time < ms)
		usleep(1);
}
