/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:20:36 by fras          #+#    #+#                 */
/*   Updated: 2024/01/25 17:07:15 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(t_exit_codes exit_code)
{
	if (exit_code == MALLOC_FAILED)
		ft_putstr_fd("philo: error malloc_failed\n", STDERR_FILENO);
	if (exit_code == INVALID_INPUT)
		ft_putstr_fd("philo: error invalid input\n", STDERR_FILENO);
}

void	print_error_specify_invalid_input(t_info_type specify)
{
	if (specify == TOTAL_PHILOSOPHERS)
		ft_putstr_fd(_RED "number of NUMBER_OF_PHILOSOPHERS must be between 1"\
			" and 200\n"_RESET, STDERR_FILENO);
	if (specify == DIE_TIME)
		ft_putstr_fd(_RED "number of TIME_TO_DIE must be between 0 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == EAT_TIME)
		ft_putstr_fd(_RED "number of TIME_TO_EAT must be between 0 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == SLEEP_TIME)
		ft_putstr_fd(_RED "number of TIME_TO_SLEEP must be between 0 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == NUMBER_OF_MEALS)
		ft_putstr_fd(_RED "number of NUMBER_OF_TIMES_PHILOSOPHERS_MUST_EAT "\
			"must be between 0 and 999999999\n"_RESET, STDERR_FILENO);
	if (specify == UNEXPECTED_NUMBER_OF_ARGUMENTS)
		ft_putstr_fd(_RED "number of arguments must be 4 or 5\n" _RESET, \
			STDERR_FILENO);
}
