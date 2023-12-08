/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:49:54 by fras          #+#    #+#                 */
/*   Updated: 2023/12/08 18:38:11 by fras          ########   odam.nl         */
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
	SUCCESSFULLY,
	MALLOC_FAILED,
	INVALID_INPUT
}	t_exit_codes;

typedef enum e_invalid_input_type
{
	UNEXPECTED_NUMBER_OF_ARGUMENTS,
	INCORRECT_NUMBER_OF_PHILOSOPHERS,
	INCORRECT_TIME_TO_DIE,
	INCORRECT_TIME_TO_EAT,
	INCORRECT_TIME_TO_SLEEP,
	INCORRECT_NUMBER_OF_TIMES_PHILOSOPHERS_MUST_EAT
}	t_invalid_input_type;

#endif