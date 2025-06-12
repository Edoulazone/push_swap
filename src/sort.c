/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:21:03 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:28:52 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_elements_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	elements_moved;
	int	operations_count;

	stack_size = get_stack_size(*stack_a);
	elements_moved = 0;
	operations_count = 0;
	while (stack_size > 6 && operations_count < stack_size && elements_moved < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_to_stack_b(stack_a, stack_b);
			elements_moved++;
		}
		else
			rotate_stack_a_up(stack_a);
		operations_count++;
	}
	while (stack_size - elements_moved > 3)
	{
		push_to_stack_b(stack_a, stack_b);
		elements_moved++;
	}
}

static void	position_smallest_element_on_top(t_stack **stack_a)
{
	int	smallest_position;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	smallest_position = find_smallest_element_position(stack_a);
	if (smallest_position > stack_size / 2)
	{
		while (smallest_position < stack_size)
		{
			rotate_stack_a_down(stack_a);
			smallest_position++;
		}
	}
	else
	{
		while (smallest_position > 0)
		{
			rotate_stack_a_up(stack_a);
			smallest_position--;
		}
	}
}

void	sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	move_elements_to_stack_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	while (*stack_b)
	{
		calculate_target_positions(stack_a, stack_b);
		calculate_movement_costs(stack_a, stack_b);
		execute_most_efficient_move(stack_a, stack_b);
	}
	if (!is_stack_sorted(*stack_a))
		position_smallest_element_on_top(stack_a);
}
