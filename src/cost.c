/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:13:47 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:29:27 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_movement_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	t_stack	*current_a;
	int		size_a;
	int		size_b;

	current_a = *stack_a;
	current_b = *stack_b;
	size_a = get_stack_size(current_a);
	size_b = get_stack_size(current_b);
	while (current_b)
	{
		current_b->cost_b = current_b->pos;
		if (current_b->pos > size_b / 2)
			current_b->cost_b = (size_b - current_b->pos) * -1;
		current_b->cost_a = current_b->target_pos;
		if (current_b->target_pos > size_a / 2)
			current_b->cost_a = (size_a - current_b->target_pos) * -1;
		current_b = current_b->next;
	}
}

void	execute_most_efficient_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		lowest_cost;
	int		optimal_cost_a;
	int		optimal_cost_b;

	current = *stack_b;
	lowest_cost = INT_MAX;
	while (current)
	{
		if (get_absolute_value(current->cost_a) + get_absolute_value(current->cost_b) < get_absolute_value(lowest_cost))
		{
			lowest_cost = get_absolute_value(current->cost_b) + get_absolute_value(current->cost_a);
			optimal_cost_a = current->cost_a;
			optimal_cost_b = current->cost_b;
		}
		current = current->next;
	}
	execute_move_sequence(stack_a, stack_b, optimal_cost_a, optimal_cost_b);
}
