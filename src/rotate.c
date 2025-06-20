/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:11:57 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:42:54 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack_up(t_stack **stack)
{
	t_stack	*first_element;
	t_stack	*last_element;

	if (!*stack || !(*stack)->next)
		return ;
	first_element = *stack;
	*stack = (*stack)->next;
	last_element = get_stack_bottom(*stack);
	first_element->next = NULL;
	last_element->next = first_element;
}

void	rotate_stack_a_up(t_stack **stack_a)
{
	rotate_stack_up(stack_a);
	ft_putstr("ra\n");
}

void	rotate_stack_b_up(t_stack **stack_b)
{
	rotate_stack_up(stack_b);
	ft_putstr("rb\n");
}

void	rotate_both_stacks_up(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack_up(stack_a);
	rotate_stack_up(stack_b);
	ft_putstr("rr\n");
}
