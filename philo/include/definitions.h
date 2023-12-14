/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:49:54 by fras          #+#    #+#                 */
/*   Updated: 2023/12/14 16:35:44 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define MAX_INPUT_VALUE 1000000000
# define _RED		"\e[1;31m"
# define _WHITE		"\e[1;37m"
# define _RESET		"\e[0m"

typedef enum e_exit_codes
{
	MALLOC_FAILED = 1,
	INVALID_INPUT
}	t_exit_codes;

typedef enum e_input_type
{
	NUMBER_OF_PHILOSOPHERS,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	NUMBER_OF_TIMES_PHILOSOPHERS_MUST_EAT,
	UNEXPECTED_NUMBER_OF_ARGUMENTS
}	t_input_type;

#endif