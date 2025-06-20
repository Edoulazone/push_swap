/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:21:03 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:41:08 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_elements_in_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	chunk_size;
	int	elements_pushed;
	int	current_chunk;

	stack_size = get_stack_size(*stack_a);
	chunk_size = stack_size / 3;
	elements_pushed = 0;
	current_chunk = 1;
	while (get_stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index <= chunk_size * current_chunk)
		{
			push_to_stack_b(stack_a, stack_b);
			elements_pushed++;
			if (elements_pushed >= chunk_size && current_chunk < 3)
			{
				current_chunk++;
				elements_pushed = 0;
			}
		}
		else
			rotate_stack_a_up(stack_a);
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

void	enhanced_sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	push_elements_in_chunks(stack_a, stack_b);
	sort_three_elements(stack_a);
	while (*stack_b)
	{
		calculate_target_positions(stack_a, stack_b);
		enhanced_calculate_costs(stack_a, stack_b);
		find_optimal_move(stack_a, stack_b);
	}
	if (!is_stack_sorted(*stack_a))
		position_smallest_element_on_top(stack_a);
}

static void	move_min_to_stack_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	min_pos;

	min_pos = find_smallest_element_position(stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			rotate_stack_a_up(stack_a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rotate_stack_a_down(stack_a);
			min_pos++;
		}
	}
	push_to_stack_b(stack_a, stack_b);
}

void	sort_small_stack_optimized(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = get_stack_size(*stack_a);
	while (size > 3)
	{
		move_min_to_stack_b(stack_a, &stack_b, size);
		size--;
	}
	sort_three_elements(stack_a);
	while (stack_b)
		push_to_stack_a(stack_a, &stack_b);
}
