/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:49:54 by fras          #+#    #+#                 */
/*   Updated: 2024/01/23 17:05:18 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define _RED		"\e[1;31m"
# define _WHITE		"\e[1;37m"
# define _RESET		"\e[0m"

typedef enum e_exit_codes
{
	MALLOC_FAILED = 1,
	INVALID_INPUT
}	t_exit_codes;

typedef enum e_input_type
{
	TOTAL_PHILOSOPHERS,
	DIE_TIME,
	EAT_TIME,
	SLEEP_TIME,
	NUMBER_OF_MEALS,
	UNEXPECTED_NUMBER_OF_ARGUMENTS
}	t_input_type;

typedef struct s_philo
{
	uint8_t			id;
	pthread_t		thread;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
}	t_philo;

typedef struct s_mutex_group
{
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	finish;
}	t_mutex_group;

typedef struct s_main
{
	t_philo			*philos;
	t_mutex_group	*mutex;
	bool			finished;
}	t_main;

#endif