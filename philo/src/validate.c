/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:44:22 by fras          #+#    #+#                 */
/*   Updated: 2023/12/14 17:07:54 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	valid_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		print_error_specify_invalid_input(UNEXPECTED_NUMBER_OF_ARGUMENTS);
		print_error(INVALID_INPUT);
		return (false);
	}
	while (++i < argc)
	{
		if (!string_is_digit_only(argv[i]) || !below_max_digits(9, argv[i]))
		{
			print_error_specify_invalid_input(i - 1);
			print_error(INVALID_INPUT);
			return (false);
		}
	}
	return (true);
}

bool	below_max_digits(int max_digits, char *string)
{
	int	i;

	i = 0;
	while (ft_isdigit(string[i]) && string[i])
	{
		if (i > max_digits - 1)
			return (false);
		i++;
	}
	return (true);
}
