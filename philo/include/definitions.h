/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:49:54 by fras          #+#    #+#                 */
/*   Updated: 2024/01/23 20:26:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define _RED		"\e[1;31m"
# define _WHITE		"\e[1;37m"
# define _RESET		"\e[0m"
# define LEFT		0
# define RIGHT		1

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
	uint8_t			fork_id[2];
}	t_philo;

typedef struct s_mutex_group
{
	pthread_mutex_t	fork[200];
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	finish;
}	t_mutex_group;

typedef struct s_general
{
	int				start_data[5];
	t_mutex_group	mutex;
	bool			finished;
}	t_general;

#endif