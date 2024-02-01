/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:49:54 by fras          #+#    #+#                 */
/*   Updated: 2024/01/31 17:27:10 by fras          ########   odam.nl         */
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
	INVALID_INPUT = 1,
	MALLOC_FAILED,
	MUTEX_FAILED
}	t_exit_codes;

typedef enum e_info_type
{
	TOTAL_PHILOSOPHERS,
	DIE_TIME,
	EAT_TIME,
	SLEEP_TIME,
	NUMBER_OF_MEALS,
	PHILO_FINISHED,
	UNEXPECTED_NUMBER_OF_ARGUMENTS
}	t_info_type;

typedef enum e_philo_status
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_philo_status;


typedef struct s_mutex_group
{
	pthread_mutex_t	fork[200];
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	finish;
}	t_mutex_group;

typedef struct s_general
{
	int				info[6];
	struct s_philo	*philos;
	t_mutex_group	mutex;
}	t_general;

typedef struct s_philo
{
	uint8_t			id;
	pthread_t		thread;
	int				meal_count;
	uint64_t		last_meal_time;
	uint8_t			fork_id[2];
	t_general		*general;
}	t_philo;

#endif