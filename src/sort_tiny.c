/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:35:07 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:29:10 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_largest_element_index(t_stack *stack)
{
	int		largest_index;

	largest_index = stack->index;
	while (stack)
	{
		if (stack->index > largest_index)
			largest_index = stack->index;
		stack = stack->next;
	}
	return (largest_index);
}

void	sort_three_elements(t_stack **stack)
{
	int		largest_index;

	if (is_stack_sorted(*stack))
		return ;
	largest_index = find_largest_element_index(*stack);
	if ((*stack)->index == largest_index)
		rotate_stack_a_up(stack);
	else if ((*stack)->next->index == largest_index)
		rotate_stack_a_down(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap_top_two(stack);
}
