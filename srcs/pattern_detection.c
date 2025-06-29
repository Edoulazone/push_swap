/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_detection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:18:55 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:38:56 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	detect_ascending_sequence(t_stack *b)
{
	t_node	*current;
	int		sequence_length;

	if (!b || b->size < 2)
		return (0);
	current = b->top;
	sequence_length = 1;
	while (current->next && sequence_length < 4)
	{
		if (current->value < current->next->value)
			sequence_length++;
		else
			break ;
		current = current->next;
	}
	return (sequence_length);
}

static int	detect_descending_sequence(t_stack *b)
{
	t_node	*current;
	int		sequence_length;

	if (!b || b->size < 2)
		return (0);
	current = b->top;
	sequence_length = 1;
	while (current->next && sequence_length < 4)
	{
		if (current->value > current->next->value)
			sequence_length++;
		else
			break ;
		current = current->next;
	}
	return (sequence_length);
}

static int	calculate_pattern_bonus(int pattern_length)
{
	if (pattern_length >= 4)
		return (4);
	if (pattern_length == 3)
		return (2);
	if (pattern_length == 2)
		return (1);
	return (0);
}

static void	apply_pattern_to_node(t_node *current, int asc_length,
		int desc_length)
{
	int	pattern_bonus;

	if (asc_length > desc_length)
		pattern_bonus = calculate_pattern_bonus(asc_length);
	else
		pattern_bonus = calculate_pattern_bonus(desc_length);
	if (current->push_cost > pattern_bonus)
		current->push_cost -= pattern_bonus;
}

void	apply_pattern_optimization(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		asc_length;
	int		desc_length;

	(void)a;
	current = b->top;
	while (current)
	{
		asc_length = detect_ascending_sequence(b);
		desc_length = detect_descending_sequence(b);
		apply_pattern_to_node(current, asc_length, desc_length);
		current = current->next;
	}
}
