/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:15 by fras          #+#    #+#                 */
/*   Updated: 2024/02/05 16:28:52 by fras          ########   odam.nl         */
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
		return (print_error(MALLOC_FAILED_PHILOS));
	if (init_mutex(&general.mutex, general.info[TOTAL_PHILOSOPHERS]))
		return (free(general.philos), free(general.mutex.fork), MUTEX_FAILED);
	if (!run_philo(&general))
		return (free(general.philos), free(general.mutex.fork), destroy_mutex(\
				&general.mutex, general.info[TOTAL_PHILOSOPHERS], 4), \
				CREATE_THREAD_FAILED);
	check_philo(&general);
	end_philo(general);
	destroy_mutex(&general.mutex, general.info[TOTAL_PHILOSOPHERS], 4);
	return (free(general.philos), free(general.mutex.fork), EXIT_SUCCESS);
}
