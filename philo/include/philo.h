/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:40:18 by fras          #+#    #+#                 */
/*   Updated: 2023/12/08 18:38:15 by fras          ########   odam.nl         */
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
# include "definitions.h"
# include "libft.h"
# include "libftextended.h"

// Philo

// Error
void	print_error(t_exit_codes exit_code);
void	print_specify_invalid_input(t_invalid_input_type specify);

// Validate
bool	valid_input(int argc, char **argv);

#endif