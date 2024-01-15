/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:17:52 by fras          #+#    #+#                 */
/*   Updated: 2024/01/15 17:45:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
