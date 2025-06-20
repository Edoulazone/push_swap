/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:04:17 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:40:30 by eschmitz         ###   ########.fr       */
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
			add_node_to_stack_bottom(&stack_a,
				create_new_stack_node((int)number));
		i++;
	}
	return (stack_a);
}

void	optimized_assign_indices(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		rank;

	current = stack_a;
	while (current)
	{
		rank = 1;
		compare = stack_a;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}
