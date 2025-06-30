/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:00:00 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/30 20:27:22 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simulate_move_cost(t_stack *a, t_stack *b, t_node *node)
{
	int	pos_a;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	if (!node || !node->target)
		return (INT_MAX);
	pos_a = find_position(a, node->target->value);
	pos_b = find_position(b, node->value);
	if (pos_a == -1 || pos_b == -1)
		return (INT_MAX);
	cost_a = rotation_cost(pos_a, a->size);
	cost_b = rotation_cost(pos_b, b->size);
	return (calculate_combined_cost(cost_a, cost_b) + 1);
}

int	calculate_combined_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	if (cost_a < 0)
		abs_a = -cost_a;
	else
		abs_a = cost_a;
	if (cost_b < 0)
		abs_b = -cost_b;
	else
		abs_b = cost_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	return (abs_a + abs_b);
}
