/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primary.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:18 by fras          #+#    #+#                 */
/*   Updated: 2024/02/03 20:01:35 by fras          ########   odam.nl         */
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

void	check_philo(t_general *general)
{
	t_philo	*philo;
	uint8_t	philos_to_check;
	uint8_t	meal_checker;

	philo = general->philos;
	philos_to_check = general->info[TOTAL_PHILOSOPHERS];
	meal_checker = 0;
	while (1)
	{
		pthread_mutex_lock(&general->mutex.eat);
		while (philos_to_check--)
		{
			if (philos_ate_enough(philo, &meal_checker))
				return ;
			if (philo_dead(philo))
				return ;
			philo++;
		}
		meal_checker = 0;
		pthread_mutex_unlock(&general->mutex.eat);
		usleep(1000);
	}
}

bool	philos_ate_enough(t_philo *philo, uint8_t *meal_checker)
{
	if (philo->meal_count >= philo->general->info[NUMBER_OF_MEALS])
		(*meal_checker)++;
	if (*meal_checker == philo->general->info[TOTAL_PHILOSOPHERS])
	{	
		is_finished(philo->general, true);
		printf("Bellies full, FINITO..\n");
		pthread_mutex_unlock(&philo->general->mutex.eat);
		return (true);
	}
	return (false);
}

bool	philo_dead(t_philo *philo)
{
	if (philo->last_meal_time >= get_time())
	{
		is_finished(philo->general, true);
		print_status(philo->id, DIED, philo->general->mutex);
		pthread_mutex_unlock(&philo->general->mutex.eat);
		return (true);
	}
	return (false);
}

void	end_philo(t_general general)
{
	while (general.info[TOTAL_PHILOSOPHERS]--)
	{
		pthread_mutex_lock(&general.mutex.print);
		printf("id: %d\n", general.philos->id);
		pthread_mutex_unlock(&general.mutex.print);
		pthread_join(general.philos->thread, NULL);
		general.philos++;
	}
}
