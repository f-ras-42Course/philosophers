/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:44:22 by fras          #+#    #+#                 */
/*   Updated: 2024/02/05 16:39:13 by fras          ########   odam.nl         */
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
		if (!string_is_digit_only(argv[i]) || !below_max_digits(9, argv[i])
			|| (argv[i][0] == '0' && !argv[i][1]))
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

// bool	under_two_hundred(char *string)
// {
// 	if (ft_strlen(string) > 3 \
// 		|| (ft_strlen(string) == 3 && string[0] > '2')
// 		|| (ft_strlen(string) > 1 \
// 		&& (string[0] == '2' && (string[1] > '0' || string[2] > '0'))))
// 		return (false);
// 	return (true);
// }
