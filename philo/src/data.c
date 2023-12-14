/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 17:17:52 by fras          #+#    #+#                 */
/*   Updated: 2023/12/14 17:24:20 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	insert_data(int data[], int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		data[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (i == 4)
		data[i] = -1;
}
