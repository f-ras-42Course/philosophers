/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:15 by fras          #+#    #+#                 */
/*   Updated: 2024/01/25 18:20:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_general		general;

	if (!init_info(general.info, argc, argv))
		return (INVALID_INPUT);
	general.philos = init_philosophers(general.info[TOTAL_PHILOSOPHERS]);
	if (!general.philos)
		return (print_error(MALLOC_FAILED), MALLOC_FAILED);
	run_philo(general.philos, general.info);
	print_status(12, TAKING_FORK);
	// test();
	return (EXIT_SUCCESS);
}
