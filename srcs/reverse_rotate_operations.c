/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:12:25 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:36:36 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	if (stack->size == 2)
	{
		stack->top->next = first;
		return ;
	}
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

static void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || stack->size < 2)
		return ;
	if (stack->size == 2)
	{
		rotate_stack(stack);
		return ;
	}
	second_last = stack->top;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_putstr("rrr\n");
}
