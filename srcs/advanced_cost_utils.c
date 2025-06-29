/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_cost_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:18:08 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:36:48 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_next_node_in_stack(t_stack *stack, t_node *current)
{
	if (!current || !current->next)
		return (stack->top);
	return (current->next);
}

static int	calculate_sequence_cost(t_stack *a, t_stack *b, t_node *first,
		int depth)
{
	t_node	*next_node;
	int		first_cost;
	int		sequence_cost;
	int		total_cost;

	if (depth <= 0 || !first)
		return (0);
	first_cost = simulate_move_cost(a, b, first);
	if (first_cost == INT_MAX || b->size <= 1)
		return (first_cost);
	next_node = get_next_node_in_stack(b, first);
	if (!next_node || next_node == first)
		return (first_cost);
	sequence_cost = calculate_sequence_cost(a, b, next_node, depth - 1);
	if (sequence_cost == INT_MAX)
		return (first_cost);
	total_cost = first_cost + sequence_cost;
	if (total_cost < first_cost)
		return (INT_MAX);
	return (total_cost);
}

static void	calculate_advanced_cost_for_node(t_stack *a, t_stack *b,
		t_node *current, int lookahead)
{
	int	basic_cost;
	int	advanced_cost;
	int	depth;
	int	sequence_cost;

	basic_cost = simulate_move_cost(a, b, current);
	advanced_cost = basic_cost;
	depth = 1;
	while (depth <= lookahead && b->size > depth)
	{
		sequence_cost = calculate_sequence_cost(a, b, current, depth);
		if (sequence_cost < advanced_cost)
			advanced_cost = sequence_cost;
		depth++;
	}
	current->push_cost = advanced_cost;
}

void	calculate_advanced_costs(t_stack *a, t_stack *b, int lookahead)
{
	t_node	*current;

	if (lookahead < 1)
		lookahead = 1;
	if (lookahead > 3)
		lookahead = 3;
	current = b->top;
	while (current)
	{
		calculate_advanced_cost_for_node(a, b, current, lookahead);
		current = current->next;
	}
}
