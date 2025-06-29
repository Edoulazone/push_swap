/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_detection_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:23:35 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:23:45 by eschmitz         ###   ########.fr       */
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

int	has_beneficial_pattern(t_stack *b)
{
	int	asc_length;
	int	desc_length;

	asc_length = detect_ascending_sequence(b);
	desc_length = detect_descending_sequence(b);
	return (asc_length >= 2 || desc_length >= 2);
}
