/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:15 by fras          #+#    #+#                 */
/*   Updated: 2024/02/03 17:18:00 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_general		general;

	if (!init_info(general.info, argc, argv))
		return (INVALID_INPUT);
	general.philos = \
		init_philosophers(general.info[TOTAL_PHILOSOPHERS], &general);
	if (!general.philos)
		return (print_error(MALLOC_FAILED), MALLOC_FAILED);
	if (!init_mutex(&general.mutex))
		return (free(general.philos), print_error(MUTEX_FAILED), MUTEX_FAILED);
	run_philo(&general);
	check_philo(&general);
	end_philo(general);
	destroy_mutex(&general.mutex);
	free(general.philos);
	return (EXIT_SUCCESS);
}
