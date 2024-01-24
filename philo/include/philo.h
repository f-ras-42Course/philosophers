/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:40:18 by fras          #+#    #+#                 */
/*   Updated: 2024/01/24 17:34:26 by fras          ########   odam.nl         */
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

// Error
void		print_error(t_exit_codes exit_code);
void		print_error_specify_invalid_input(t_info_type specify);

// Validate
bool		valid_input(int argc, char **argv);
bool		below_max_digits(int max_digits, char *string);
bool		under_two_hundred(char *string);

// Data
void		insert_data(int start_data[], int argc, char **argv);

// Philo
void		run_philo(t_philo *philos, int start_data[]);

// Philosophers
t_philo		*init_philosophers(int amount);
//void		clean_philosophers(t_philo *philos, int amount); -- might not be necesarry.

// Status
void		print_status(uint8_t id, t_philo_status what);
char		*doing(t_philo_status what);

// Time

uint64_t	get_time(void);

#endif