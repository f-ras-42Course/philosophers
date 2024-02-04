/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 16:07:54 by fras          #+#    #+#                 */
/*   Updated: 2024/02/04 14:42:56 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// notes made in run_philo and below
// check alive status in run_philo, update last meal time in philosopher_routine

void	*philosopher_routine(void *ptr)
{
	t_philo		*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(philo->general->info[EAT_TIME] * 1000);
	while (!philo->general->info[FINISHED])
	{
		if (!is_finished(philo->general, false))
			thinking(philo);
		if (!is_finished(philo->general, false))	
			eating(philo);
		if (!is_finished(philo->general, false))
			sleeping(philo);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	print_status(philo->id, THINKING, philo->general->mutex);
}

void	eating(t_philo *philo)
{
	pthread_mutex_t	*fork;

	fork = philo->general->mutex.fork;
	pthread_mutex_lock(&fork[philo->fork_id[LEFT]]);
	print_status(philo->id, TAKING_FORK, philo->general->mutex);
	pthread_mutex_lock(&fork[philo->fork_id[RIGHT]]);
	print_status(philo->id, TAKING_FORK, philo->general->mutex);
	pthread_mutex_lock(&philo->general->mutex.eat);
	philo->last_meal_time = \
		print_status(philo->id, EATING, philo->general->mutex);
	pthread_mutex_unlock(&philo->general->mutex.eat);
	ms_sleep(philo->general, philo->general->info[EAT_TIME]);
	pthread_mutex_unlock(&fork[philo->fork_id[LEFT]]);
	pthread_mutex_unlock(&fork[philo->fork_id[RIGHT]]);
	pthread_mutex_lock(&philo->general->mutex.eat);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->general->mutex.eat);
}


void	sleeping(t_philo *philo)
{
	print_status(philo->id, SLEEPING, philo->general->mutex);
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
