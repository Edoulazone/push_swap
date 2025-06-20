/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:10:39 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:43:05 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack_down(t_stack **stack)
{
	t_stack	*last_element;
	t_stack	*second_last;
	t_stack	*first_element;

	if (!*stack || !(*stack)->next)
		return ;
	last_element = get_stack_bottom(*stack);
	second_last = get_stack_before_bottom(*stack);
	first_element = *stack;
	*stack = last_element;
	(*stack)->next = first_element;
	second_last->next = NULL;
}

void	rotate_stack_a_down(t_stack **stack_a)
{
	rotate_stack_down(stack_a);
	ft_putstr("rra\n");
}

void	rotate_stack_b_down(t_stack **stack_b)
{
	rotate_stack_down(stack_b);
	ft_putstr("rrb\n");
}

void	rotate_both_stacks_down(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack_down(stack_a);
	rotate_stack_down(stack_b);
	ft_putstr("rrr\n");
}
