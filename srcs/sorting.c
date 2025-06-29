/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:33:17 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:13:03 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_small(a, b);
	else
		sort_large_optimized(a, b);
}

static void	sort_three_helper(t_stack *a, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3 || is_sorted(a))
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	sort_three_helper(a, first, second, third);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = find_position(a, stack_min(a));
		rotate_to_position(a, min_pos, 'a');
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
