/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:32:14 by eschmitz          #+#    #+#             */
/*   Updated: 2025/07/01 15:40:29 by eschmitz         ###   ########.fr       */
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

void	ra(t_stack *a)
{
	rotate_stack(a);
	ft_putstr("ra\n");
}

void	rap(t_stack *a)
{
	rotate_stack(a);
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	ft_putstr("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr("rr\n");
}
