/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 21:04:23 by fras          #+#    #+#                 */
/*   Updated: 2024/01/23 21:24:05 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philosophers(int amount)
{
	t_philo	*initialize;
	int		i;

	i = 0;
	initialize = malloc(amount * sizeof(t_philo));
	if (!initialize)
		return (NULL);
	while (amount--)
	{
		printf("i: %d\n", i);
		initialize[i].id = i + 1;
		initialize[i].fork_pos[LEFT] = i;
		initialize[i].fork_pos[RIGHT] = (i + 1) % amount;
		printf("i: %d\n", i);
		i++;
	}
	return (initialize);
}
