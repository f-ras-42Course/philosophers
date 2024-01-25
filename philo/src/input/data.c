/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:17:52 by fras          #+#    #+#                 */
/*   Updated: 2024/01/25 17:53:55 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_info(int start_data[], int argc, char **argv)
{
	if (!valid_input(argc, argv))
		return (false);
	insert_data(start_data, argc, argv);
	return (true);
}

void	insert_data(int start_data[], int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		start_data[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (i == 4)
		start_data[i] = -1;
}
