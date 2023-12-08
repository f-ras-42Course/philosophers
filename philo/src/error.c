/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:20:36 by fras          #+#    #+#                 */
/*   Updated: 2023/12/08 19:08:38 by fras          ########   odam.nl         */
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

void	print_specify_invalid_input(t_invalid_input_type specify)
{
	if (specify == UNEXPECTED_NUMBER_OF_ARGUMENTS)
		ft_putstr_fd(_RED "number of arguments must be 4 or 5\n" _RESET, \
			STDERR_FILENO);
	if (specify == INCORRECT_NUMBER_OF_PHILOSOPHERS)
		ft_putstr_fd(_RED "number of NUMBER_OF_PHILOSOPHERS must be between 1"\
			" and 999999999\n"_RESET, STDERR_FILENO);
	if (specify == INCORRECT_TIME_TO_DIE)
		ft_putstr_fd(_RED "number of TIME_TO_DIE must be between 0 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == INCORRECT_TIME_TO_EAT)
		ft_putstr_fd(_RED "number of TIME_TO_EAT must be between 0 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == INCORRECT_TIME_TO_SLEEP)
		ft_putstr_fd(_RED "number of TIME_TO_SLEEP must be between 0 and"\
			" 999999999\n"_RESET, STDERR_FILENO);
	if (specify == INCORRECT_NUMBER_OF_TIMES_PHILOSOPHERS_MUST_EAT)
		ft_putstr_fd(_RED "number of NUMBER_OF_TIMES_PHILOSOPHERS_MUST_EAT "\
			"must be between 0 and 999999999\n"_RESET, STDERR_FILENO);
}
