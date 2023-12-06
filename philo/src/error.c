/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:20:36 by fras          #+#    #+#                 */
/*   Updated: 2023/12/06 15:15:31 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(t_exit_codes exit_code)
{
	if (exit_code == MALLOC_FAILED)
		ft_putstr_fd("philo: error malloc_failed\n", STDERR_FILENO);
}
