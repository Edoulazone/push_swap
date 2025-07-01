/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:32:26 by eschmitz          #+#    #+#             */
/*   Updated: 2025/07/01 15:41:02 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_and_add_number(char *str, t_stack *stack_a)
{
	long	value;
	t_node	*node;

	if (!is_valid_number(str))
		return (0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	node = node_create((int)value);
	if (!node)
		return (0);
	stack_push(stack_a, node);
	rap(stack_a);
	return (1);
}

static int	parse_single_arg(char *arg, t_stack *stack_a)
{
	char	**numbers;
	int		i;

	
	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!validate_and_add_number(numbers[i], stack_a))
		{
			free_split(numbers);
			return (0);
		}
		i++;
	}
	free_split(numbers);
	return (1);
}

static int	parse_multiple_args(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		if (!validate_and_add_number(argv[i], stack_a))
			return (0);
		i--;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int	result;

	if (argc == 2)
		result = parse_single_arg(argv[1], stack_a);
	else
		result = parse_multiple_args(argc, argv, stack_a);
	if (!result)
		return (0);
	if (has_duplicates(stack_a))
		return (0);
	return (1);
}
