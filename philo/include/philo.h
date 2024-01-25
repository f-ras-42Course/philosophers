/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:40:18 by fras          #+#    #+#                 */
/*   Updated: 2024/01/25 21:02:57 by fras          ########   odam.nl         */
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
void		print_status(uint8_t id, t_philo_status what);
char		*doing(t_philo_status what);

// Time
uint64_t	get_time(void);

// Error
void		print_error(t_exit_codes exit_code);
void		print_error_specify_invalid_input(t_info_type specify);

//______________________________________________________________________________

//  --    THREADS    --

// Philosophers
t_philo		*init_philosophers(int amount);

// Mutex
bool		init_mutex(t_mutex_group *mutex);
void		destroy_mutex(t_mutex_group *mutex);
void		destroy_fork_mutex(pthread_mutex_t *forks, int amount);

//______________________________________________________________________________

// --    MAIN    --

// Philo
void		run_philo(t_general general);
//______________________________________________________________________________


#endif