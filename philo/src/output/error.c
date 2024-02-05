/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:20:36 by fras          #+#    #+#                 */
/*   Updated: 2024/02/05 16:40:16 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(t_exit_codes exit_code)
{
	if (exit_code == INVALID_INPUT)
		ft_putstr_fd("philo: error invalid input\n", STDERR_FILENO);
	if (exit_code == MALLOC_FAILED_PHILOS)
		ft_putstr_fd("philo: error malloc_failed in philos\n", STDERR_FILENO);
	if (exit_code == MALLOC_FAILED_MUTEX)
		ft_putstr_fd("philo: error malloc_failed in mutex\n", STDERR_FILENO);
	if (exit_code == MUTEX_FAILED)
		ft_putstr_fd("philo: error mutex_failed\n", STDERR_FILENO);
	if (exit_code == CREATE_THREAD_FAILED)
		ft_putstr_fd("philo: error create_thread_failed\n", STDERR_FILENO);
	return (exit_code);
}

void	print_error_specify_invalid_input(t_info_type specify)
{
	if (specify == TOTAL_PHILOSOPHERS)
		ft_putstr_fd(_RED "number of NUMBER_OF_PHILOSOPHERS must be between 1"\
			" and 999999999\n"_RESET, STDERR_FILENO);
	if (specify == DIE_TIME)
		ft_putstr_fd(_RED "number of TIME_TO_DIE must be between 1 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == EAT_TIME)
		ft_putstr_fd(_RED "number of TIME_TO_EAT must be between 1 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == SLEEP_TIME)
		ft_putstr_fd(_RED "number of TIME_TO_SLEEP must be between 1 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == NUMBER_OF_MEALS)
		ft_putstr_fd(_RED "number of NUMBER_OF_TIMES_PHILOSOPHERS_MUST_EAT "\
			"must be between 1 and 999999999\n"_RESET, STDERR_FILENO);
	if (specify == UNEXPECTED_NUMBER_OF_ARGUMENTS)
		ft_putstr_fd(_RED "number of arguments must be 4 or 5\n" _RESET, \
			STDERR_FILENO);
}
