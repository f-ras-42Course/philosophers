/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:03:15 by fras          #+#    #+#                 */
/*   Updated: 2024/01/23 17:01:47 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		start_data[5];
	t_philo	*philos;

	if (!valid_input(argc, argv))
		return (INVALID_INPUT);
	insert_data(start_data, argc, argv);
	philos = init_philosophers(start_data[TOTAL_PHILOSOPHERS]);
	if (!philos)
		return (print_error(MALLOC_FAILED), MALLOC_FAILED);
	run_philo(philos, start_data);
	return (EXIT_SUCCESS);
}
