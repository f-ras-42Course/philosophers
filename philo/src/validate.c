/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:44:22 by fras          #+#    #+#                 */
/*   Updated: 2023/12/08 18:35:05 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	valid_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		print_specify_invalid_input(i);
		print_error(INVALID_INPUT);
		return (false);
	}
	while (++i < argc)
	{
		if (!string_is_digit_only(argv[i]))
		{
			print_specify_invalid_input(i);
			print_error(INVALID_INPUT);
			return (false);
		}
	}
	return (true);
}
