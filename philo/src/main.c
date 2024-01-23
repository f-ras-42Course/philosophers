/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:15 by fras          #+#    #+#                 */
/*   Updated: 2024/01/23 20:59:59 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_general		info;
	t_philo			*philos;
	// t_mutex_group	mutex;

	if (!valid_input(argc, argv))
		return (INVALID_INPUT);
	insert_data(info.start_data, argc, argv);
	philos = init_philosophers(info.start_data[TOTAL_PHILOSOPHERS]);
	if (!philos)
		return (print_error(MALLOC_FAILED), MALLOC_FAILED);
	run_philo(philos, info.start_data);
	return (EXIT_SUCCESS);
}
