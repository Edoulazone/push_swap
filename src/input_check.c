/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:42:53 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:40:47 by eschmitz         ###   ########.fr       */
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

static int	validate_number_format(const char *str)
{
	int		i;
	long	temp_result;

	if (!str || !str[0] || ft_strlen(str) > 11)
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!is_digit(str[i]))
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	temp_result = ft_atoi(str);
	if (temp_result > INT_MAX || temp_result < INT_MIN)
		return (0);
	return (1);
}

static void	sort_numbers_array(int *numbers, int count)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (numbers[j] > numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	has_duplicates_optimized(char **argv)
{
	int	*numbers;
	int	count;
	int	i;

	count = 0;
	while (argv[count + 1])
		count++;
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (1);
	i = 0;
	while (i < count)
	{
		numbers[i] = (int)ft_atoi(argv[i + 1]);
		i++;
	}
	sort_numbers_array(numbers, count);
	i = 0;
	while (i < count - 1)
	{
		if (numbers[i] == numbers[i + 1])
		{
			free(numbers);
			return (1);
		}
		i++;
	}
	free(numbers);
	return (0);
}

int	enhanced_validate_input(char **argv)
{
	int	i;
	int	arg_count;

	if (!argv || !argv[1])
		return (0);
	arg_count = 0;
	while (argv[arg_count + 1])
		arg_count++;
	if (arg_count == 0 || (arg_count == 1 && argv[1][0] == '\0'))
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!validate_number_format(argv[i]))
			return (0);
		i++;
	}
	if (has_duplicates_optimized(argv))
		return (0);
	return (1);
}

int	is_input_already_sorted(char **argv)
{
	int		i;
	long	current;
	long	next;

	if (!argv || !argv[1] || !argv[2])
		return (1);
	i = 1;
	while (argv[i] && argv[i + 1])
	{
		current = ft_atoi(argv[i]);
		next = ft_atoi(argv[i + 1]);
		if (current > next)
			return (0);
		i++;
	}
	return (1);
}
