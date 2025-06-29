/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:13:24 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:13:31 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack *a, t_stack *b)
{
	int	pushed;
	int	total;

	pushed = 0;
	total = a->size;
	while (a->size > 3 && pushed < total / 2)
	{
		if (a->top->index <= total / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	while (a->size > 3)
	{
		pb(a, b);
		pushed++;
	}
}

static void	execute_advanced_sort(t_stack *a, t_stack *b)
{
	set_targets(a, b);
	if (should_use_advanced_calculation(b))
	{
		calculate_advanced_costs(a, b, 2);
		if (has_beneficial_pattern(b))
			apply_pattern_optimization(a, b);
		execute_optimized_moves(a, b);
	}
	else
	{
		calculate_costs(a, b);
		execute_move(a, b, find_cheapest(b));
	}
}

void	sort_large_optimized(t_stack *a, t_stack *b)
{
	push_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		execute_advanced_sort(a, b);
	bring_min_to_top(a);
}
