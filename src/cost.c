/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:13:47 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:44:10 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_rotation_cost(int position, int stack_size)
{
	int	forward_cost;
	int	backward_cost;

	forward_cost = position;
	backward_cost = stack_size - position;
	if (forward_cost <= backward_cost)
		return (forward_cost);
	return (-backward_cost);
}

void	enhanced_calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	int		size_a;
	int		size_b;

	current_b = *stack_b;
	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
	while (current_b)
	{
		current_b->cost_a = calculate_rotation_cost(current_b->target_pos,
				size_a);
		current_b->cost_b = calculate_rotation_cost(current_b->pos, size_b);
		current_b = current_b->next;
	}
}

static int	calculate_move_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = get_absolute_value(cost_a);
	abs_b = get_absolute_value(cost_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

void	find_optimal_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		min_cost;
	int		optimal_cost_a;
	int		optimal_cost_b;
	int		current_cost;

	current = *stack_b;
	min_cost = INT_MAX;
	optimal_cost_a = 0;
	optimal_cost_b = 0;
	while (current)
	{
		current_cost = calculate_move_cost(current->cost_a, current->cost_b);
		if (current_cost < 3)
		{
			optimal_cost_a = current->cost_a;
			optimal_cost_b = current->cost_b;
			break ;
		}
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			optimal_cost_a = current->cost_a;
			optimal_cost_b = current->cost_b;
		}
		current = current->next;
	}
	execute_move_sequence(stack_a, stack_b, optimal_cost_a, optimal_cost_b);
}
