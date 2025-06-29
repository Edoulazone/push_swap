/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:33:54 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:17:38 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_position(t_stack *stack, int position, char stack_name)
{
	int	size;

	size = stack->size;
	if (position <= size / 2)
	{
		while (position > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
			position++;
		}
	}
}

static void	execute_both_rotations(t_stack *a, t_stack *b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	execute_remaining_rotations(t_stack *a, t_stack *b, int cost_a,
		int cost_b)
{
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

void	execute_move(t_stack *a, t_stack *b, t_node *cheapest)
{
	int	pos_a;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	if (!cheapest)
		return ;
	pos_a = find_position(a, cheapest->target->value);
	pos_b = find_position(b, cheapest->value);
	cost_a = rotation_cost(pos_a, a->size);
	cost_b = rotation_cost(pos_b, b->size);
	execute_both_rotations(a, b, &cost_a, &cost_b);
	execute_remaining_rotations(a, b, cost_a, cost_b);
	pa(a, b);
}

void	bring_min_to_top(t_stack *a)
{
	int	min_value;
	int	min_pos;

	if (is_sorted(a))
		return ;
	min_value = stack_min(a);
	min_pos = find_position(a, min_value);
	rotate_to_position(a, min_pos, 'a');
}
