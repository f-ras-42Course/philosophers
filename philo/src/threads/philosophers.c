/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 21:04:23 by fras          #+#    #+#                 */
/*   Updated: 2024/01/22 19:02:14 by fras          ########   odam.nl         */
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
	while (amount-- && (++i))
	{
		initialize[i].id = (i + 1);
	}
	return (initialize);
}
