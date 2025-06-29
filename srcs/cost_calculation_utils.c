/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:14:11 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:14:13 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = cost_a;
	if (abs_a < 0)
		abs_a = -abs_a;
	abs_b = cost_b;
	if (abs_b < 0)
		abs_b = -abs_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	return (abs_a + abs_b);
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		pos_b;
	int		pos_a;

	current = b->top;
	pos_b = 0;
	while (current)
	{
		pos_a = find_position(a, current->target->value);
		current->push_cost = calculate_total_cost(
				rotation_cost(pos_a, a->size),
				rotation_cost(pos_b, b->size));
		current = current->next;
		pos_b++;
	}
}

t_node	*find_cheapest(t_stack *b)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;

	if (!b || !b->top)
		return (NULL);
	current = b->top;
	cheapest = current;
	min_cost = current->push_cost;
	while (current)
	{
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
