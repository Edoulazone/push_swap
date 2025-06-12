/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:55:52 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:30:08 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_reverse_rotation_both(t_stack **stack_a, t_stack **stack_b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rotate_both_stacks_down(stack_a, stack_b);
	}
}

static void	execute_rotation_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_both_stacks_up(stack_a, stack_b);
	}
}

static void	execute_stack_a_rotations(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_stack_a_up(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rotate_stack_a_down(stack_a);
			(*cost)++;
		}
	}
}

static void	execute_stack_b_rotations(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate_stack_b_up(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rotate_stack_b_down(stack_b);
			(*cost)++;
		}
	}
}

void	execute_move_sequence(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		execute_reverse_rotation_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		execute_rotation_both(stack_a, stack_b, &cost_a, &cost_b);
	execute_stack_a_rotations(stack_a, &cost_a);
	execute_stack_b_rotations(stack_b, &cost_b);
	push_to_stack_a(stack_a, stack_b);
}
