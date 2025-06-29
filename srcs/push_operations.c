/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:11:38 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:11:45 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop(b);
	if (node)
	{
		stack_push(a, node);
		ft_putstr("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop(a);
	if (node)
	{
		stack_push(b, node);
		ft_putstr("pb\n");
	}
}
