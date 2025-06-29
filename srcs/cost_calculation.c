/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:33:39 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:13:45 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min_node(t_stack *a)
{
	t_node	*current;
	t_node	*target;
	int		target_value;

	target_value = INT_MAX;
	current = a->top;
	target = NULL;
	while (current)
	{
		if (current->value < target_value)
		{
			target_value = current->value;
			target = current;
		}
		current = current->next;
	}
	return (target);
}

static t_node	*find_target_node(t_stack *a, int value)
{
	t_node	*current;
	t_node	*target;
	int		target_value;

	current = a->top;
	target = NULL;
	target_value = INT_MAX;
	while (current)
	{
		if (current->value > value && current->value < target_value)
		{
			target_value = current->value;
			target = current;
		}
		current = current->next;
	}
	if (!target)
		target = find_min_node(a);
	return (target);
}

void	set_targets(t_stack *a, t_stack *b)
{
	t_node	*current;

	current = b->top;
	while (current)
	{
		current->target = find_target_node(a, current->value);
		current = current->next;
	}
}

int	rotation_cost(int position, int size)
{
	if (position <= size / 2)
		return (position);
	else
		return (position - size);
}
