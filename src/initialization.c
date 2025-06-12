/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:04:17 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:30:22 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack_from_args(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	number;
	int			i;

	stack_a = NULL;
	number = 0;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			handle_error_and_exit(&stack_a, NULL, argv);
		if (i == 1)
			stack_a = create_new_stack_node((int)number);
		else
			add_node_to_stack_bottom(&stack_a, create_new_stack_node((int)number));
		i++;
	}
	return (stack_a);
}

void	assign_sorted_indices(t_stack *stack_a, int stack_size)
{
	t_stack	*current;
	t_stack	*highest_node;
	int		highest_value;

	while (--stack_size > 0)
	{
		current = stack_a;
		highest_value = INT_MIN;
		highest_node = NULL;
		while (current)
		{
			if (current->value == INT_MIN && current->index == 0)
				current->index = 1;
			if (current->value > highest_value && current->index == 0)
			{
				highest_value = current->value;
				highest_node = current;
				current = stack_a;
			}
			else
				current = current->next;
		}
		if (highest_node != NULL)
			highest_node->index = stack_size;
	}
}
