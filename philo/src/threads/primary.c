/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primary.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:18 by fras          #+#    #+#                 */
/*   Updated: 2024/02/01 10:50:29 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_philo(t_general *general)
{
	t_philo	*philo;
	int		philos_to_create;

	philos_to_create = general->info[TOTAL_PHILOSOPHERS];
	philo = general->philos;
	while (philos_to_create--)
	{
		pthread_create(&philo->thread, NULL, \
						philosopher_routine, philo);
		philo++;
	}
}


	// philos_to_create = general->info[TOTAL_PHILOSOPHERS] / 2 \
	// 				+ (general->info[TOTAL_PHILOSOPHERS] % 2);
	// philo = general->philos;
	// while (philos_to_create--)
	// {
	// 	pthread_create(&philo->thread, NULL, \
	// 					philosopher_routine, philo);
	// 	philo += 2;
	// }
	// usleep(1000);
	// philo = general->philos + 1;
	// philos_to_create = general->info[TOTAL_PHILOSOPHERS] / 2;
	// while (philos_to_create--)
	// {
	// 	pthread_create(&philo->thread, NULL, \
	// 					philosopher_routine, philo);
	// 	philo += 2;
	// }


// void	check_philo(t_general *general)
// {

// }

void	end_philo(t_general general)
{
	usleep(200);
	while (general.info[TOTAL_PHILOSOPHERS]--)
	{
		pthread_mutex_lock(&general.mutex.print);
		printf("id: %d\n", general.philos->id);
		pthread_mutex_unlock(&general.mutex.print);
		pthread_join(general.philos->thread, NULL);
		general.philos++;
	}
}


	// uint64_t	ret;

	// ret = print_status(general.philos->id, TAKING_FORK);
	// printf("ret: %llu\n", ret);

	// while (1)
	// {
	// 	if (!dead)
	// 		continue ;
	// 	else
	// 		die;
	// 	usleep(1000);
	// }