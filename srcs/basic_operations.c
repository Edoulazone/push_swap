/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:31:42 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:11:01 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	temp = first->index;
	first->index = second->index;
	second->index = temp;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_putstr("sa\n");
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_putstr("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_putstr("ss\n");
}
