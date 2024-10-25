/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:42:53 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/02 18:04:57 by eschmitz         ###   ########.fr       */
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

static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (!argv || argv[0] == '\0')
		return (1);
	while (argv[i] == ' ')
		i++;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

static int	have_duplicates(char **argv)
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

int	is_correct_input(char **argv)
{
	int	i;

	i = 1;
	if (argv[1][0] == '\0')
		return (0);
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		ft_atoi(argv[i]);
		i++;
	}
	if (have_duplicates(argv))
		return (0);
	return (1);
}
