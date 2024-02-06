/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 16:07:54 by fras          #+#    #+#                 */
/*   Updated: 2024/02/06 12:46:08 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *ptr)
{
	t_philo		*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->general->mutex.start);
	pthread_mutex_unlock(&philo->general->mutex.start);
	if (philo->id % 2 == 0)
		usleep(philo->general->info[EAT_TIME] * 1000);
	while (!philo->general->info[FINISHED])
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINKING, philo->general->mutex);
}

void	eating(t_philo *philo)
{
	pthread_mutex_t	*fork;

	fork = philo->general->mutex.fork;
	pthread_mutex_lock(&fork[philo->fork_id[LEFT]]);
	print_status(philo, TAKING_FORK, philo->general->mutex);
	if (philo->general->info[TOTAL_PHILOSOPHERS] != 1)
	{
		pthread_mutex_lock(&fork[philo->fork_id[RIGHT]]);
		print_status(philo, TAKING_FORK, philo->general->mutex);
		pthread_mutex_lock(&philo->general->mutex.eat);
		philo->last_meal_time = \
			print_status(philo, EATING, philo->general->mutex);
		pthread_mutex_unlock(&philo->general->mutex.eat);
		ms_sleep(philo->general, philo->general->info[EAT_TIME]);
		pthread_mutex_lock(&philo->general->mutex.eat);
		philo->meal_count++;
		pthread_mutex_unlock(&philo->general->mutex.eat);
		pthread_mutex_unlock(&fork[philo->fork_id[RIGHT]]);
	}
	else
		ms_sleep(philo->general, UINT64_MAX);
	pthread_mutex_unlock(&fork[philo->fork_id[LEFT]]);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, SLEEPING, philo->general->mutex);
	ms_sleep(philo->general, philo->general->info[SLEEP_TIME]);
}

bool	is_finished(t_general *general, bool update)
{
	pthread_mutex_lock(&general->mutex.finish);
	if (general->info[FINISHED] || update == true)
	{
		general->info[FINISHED] = true;
		pthread_mutex_unlock(&general->mutex.finish);
		return (true);
	}
	pthread_mutex_unlock(&general->mutex.finish);
	return (false);
}
