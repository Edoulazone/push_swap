/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:57:31 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:41:57 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_element_positions(t_stack **stack)
{
	t_stack	*current;
	int		position;

	current = *stack;
	position = 0;
	while (current)
	{
		current->pos = position;
		current = current->next;
		position++;
	}
}

int	find_smallest_element_position(t_stack **stack)
{
	t_stack	*current;
	int		smallest_index;
	int		smallest_position;

	current = *stack;
	smallest_index = INT_MAX;
	update_element_positions(stack);
	smallest_position = current->pos;
	while (current)
	{
		if (current->index < smallest_index)
		{
			smallest_index = current->index;
			smallest_position = current->pos;
		}
		current = current->next;
	}
	return (smallest_position);
}

static int	find_optimal_target_position(t_stack **stack_a, int element_index,
								int target_index, int target_position)
{
	t_stack	*current_a;

	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->index > element_index && current_a->index < target_index)
		{
			target_index = current_a->index;
			target_position = current_a->pos;
		}
		current_a = current_a->next;
	}
	if (target_index != INT_MAX)
		return (target_position);
	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->index < target_index)
		{
			target_index = current_a->index;
			target_position = current_a->pos;
		}
		current_a = current_a->next;
	}
	return (target_position);
}

void	calculate_target_positions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	int		target_position;

	current_b = *stack_b;
	update_element_positions(stack_a);
	update_element_positions(stack_b);
	target_position = 0;
	while (current_b)
	{
		target_position = find_optimal_target_position(stack_a,
				current_b->index, INT_MAX, target_position);
		current_b->target_pos = target_position;
		current_b = current_b->next;
	}
}
