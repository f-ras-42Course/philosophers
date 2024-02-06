/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primary.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:18 by fras          #+#    #+#                 */
/*   Updated: 2024/02/06 19:25:57 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	run_philo(t_general *general)
{
	t_philo	*philo;
	int		philos_to_create;

	philos_to_create = general->info[TOTAL_PHILOSOPHERS];
	philo = general->philos;
	pthread_mutex_lock(&general->mutex.start);
	while (philos_to_create--)
	{
		if (pthread_create(&philo->thread, NULL, philosopher_routine, philo))
		{
			general->info[TOTAL_PHILOSOPHERS] = \
			(general->info[TOTAL_PHILOSOPHERS] - (philos_to_create + 1));
			is_finished(philo->general, true);
			end_philo(*general);
			print_error(CREATE_THREAD_FAILED);
			return (false);
		}
		philo++;
	}
	pthread_mutex_unlock(&general->mutex.start);
	return (true);
}

void	check_philo(t_general *general)
{
	t_philo	*philo;
	int		philos_to_check;
	int		meal_checker;

	while (1)
	{
		philo = general->philos;
		meal_checker = 0;
		philos_to_check = general->info[TOTAL_PHILOSOPHERS];
		pthread_mutex_lock(&general->mutex.eat);
		while (philos_to_check--)
		{
			if (philo->general->info[NUMBER_OF_MEALS] != -1)
				if (philos_ate_enough(philo, &meal_checker))
					return ;
			if (philo_dead(philo))
				return ;
			philo++;
		}
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
		pthread_mutex_unlock(&philo->general->mutex.eat);
		return (true);
	}
	return (false);
}

bool	philo_dead(t_philo *philo)
{
	if (get_time() - philo->last_meal_time \
		>= (uint64_t)philo->general->info[DIE_TIME])
	{
		is_finished(philo->general, true);
		print_status(philo, DIED, philo->general->mutex);
		pthread_mutex_unlock(&philo->general->mutex.eat);
		return (true);
	}
	return (false);
}

void	end_philo(t_general general)
{
	while (general.info[TOTAL_PHILOSOPHERS]--)
	{
		pthread_join(general.philos->thread, NULL);
		general.philos++;
	}
}
