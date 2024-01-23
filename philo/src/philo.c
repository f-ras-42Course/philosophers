/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:18 by fras          #+#    #+#                 */
/*   Updated: 2024/01/23 17:40:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	test_ids(t_philo *philos, int times)
{
	int i;

	i = 0;
	while (i++ < times)
	{
		printf("philo %d = id : %d\n", i, philos->id);
		philos++;
	}
}

void	run_philo(t_philo *philos, int start_data[])
{
	test_ids(philos, (start_data[TOTAL_PHILOSOPHERS]));
	free(philos);
	// pthread_create(

	// philosopher = 1;
	// while (philosopher <= start_data[TOTAL_PHILOSOPHERS])
	// {

	// 	philosopher += 2;
	// }
}
// 200

// 199 % 200 