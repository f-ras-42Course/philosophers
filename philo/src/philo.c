/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:18 by fras          #+#    #+#                 */
/*   Updated: 2024/01/25 17:09:34 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	test_ids(t_philo *philos, int times)
{
	int i;

	i = 0;
	while (i++ < times)
	{
		printf("philo [%d] \nid : %d\n", i, philos->id);
		printf("left fork : %d\n", philos->fork_id[LEFT]);
		printf("right fork : %d\n", philos->fork_id[RIGHT]);
		printf("----------------\n");
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