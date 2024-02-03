/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:40:18 by fras          #+#    #+#                 */
/*   Updated: 2024/02/03 19:58:35 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdint.h>
# include "definitions.h"
# include "utils.h"

//______________________________________________________________________________

// --    INPUT    --

// Validate
bool		valid_input(int argc, char **argv);
bool		below_max_digits(int max_digits, char *string);
bool		under_two_hundred(char *string);

// Data
bool		init_info(int info[], int argc, char **argv);
void		insert_data(int info[], int argc, char **argv);

//______________________________________________________________________________

// --    OUTPUT    --

// Status
uint64_t	print_status(uint8_t id, t_philo_status what, t_mutex_group mutex);
char		*doing(t_philo_status what);

// Time
uint64_t	get_time(void);

// Error
void		print_error(t_exit_codes exit_code);
void		print_error_specify_invalid_input(t_info_type specify);

//______________________________________________________________________________

//  --    THREADS    --

// Philosophers
t_philo		*init_philosophers(int amount, t_general *general);

// Mutex
bool		init_mutex(t_mutex_group *mutex);
void		destroy_mutex(t_mutex_group *mutex);
void		destroy_fork_mutex(pthread_mutex_t *forks, int amount);

// Routine

void		*philosopher_routine(void *ptr);
void		thinking(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
bool		is_finished(t_general *general, bool update);

// Primary
void		run_philo(t_general *general);
void		check_philo(t_general *general);
bool		philos_ate_enough(t_philo *philo, uint8_t *meal_checker);
bool		philo_dead(t_philo *philo);
void		end_philo(t_general general);

//______________________________________________________________________________

#endif