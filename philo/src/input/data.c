/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:17:52 by fras          #+#    #+#                 */
/*   Updated: 2024/02/03 17:53:26 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_info(int info[], int argc, char **argv)
{
	if (!valid_input(argc, argv))
		return (false);
	insert_data(info, argc, argv);
	return (true);
}

void	insert_data(int info[], int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		info[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (i == 4)
		info[NUMBER_OF_MEALS] = -1;
	info[FINISHED] = false;
}
