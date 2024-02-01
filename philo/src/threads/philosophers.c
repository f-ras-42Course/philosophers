/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 21:04:23 by fras          #+#    #+#                 */
/*   Updated: 2024/01/31 16:08:06 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philosophers(int amount, t_general *general)
{
	t_philo	*initialize;
	int		i;

	i = 0;
	initialize = malloc(amount * sizeof(t_philo));
	if (!initialize)
		return (NULL);
	while (amount--)
	{
		initialize[i].id = i + 1;
		initialize[i].fork_id[LEFT] = i;
		if (amount != 0)
			initialize[i].fork_id[RIGHT] = i + 1;
		else
			initialize[i].fork_id[RIGHT] = 0;
		initialize[i].meal_count = 0;
		initialize[i].last_meal_time = 0;
		initialize[i].general = general;
		i++;
	}
	return (initialize);
}
