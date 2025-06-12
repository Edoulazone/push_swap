/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:42:53 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:30:38 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_valid_number_format(char *argument)
{
	int	i;

	i = 0;
	if (!argument || argument[0] == '\0')
		return (0);
	while (argument[i] == ' ')
		i++;
	if (is_sign(argument[i]) && argument[i + 1] != '\0')
		i++;
	if (!is_digit(argument[i]))
		return (0);
	while (argument[i] && is_digit(argument[i]))
		i++;
	if (argument[i] != '\0' && !is_digit(argument[i]))
		return (0);
	return (1);
}

static int	contains_duplicate_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(char **argv)
{
	int	i;

	i = 1;
	if (!argv[1] || argv[1][0] == '\0')
		return (0);
	while (argv[i])
	{
		if (!is_valid_number_format(argv[i]))
			return (0);
		ft_atoi(argv[i]);
		i++;
	}
	if (contains_duplicate_numbers(argv))
		return (0);
	return (1);
}
