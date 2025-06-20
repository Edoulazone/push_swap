/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:03:22 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:42:44 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_element(t_stack **source, t_stack **destination)
{
	t_stack	*temp;

	if (*source == NULL)
		return ;
	temp = (*source)->next;
	(*source)->next = *destination;
	*destination = *source;
	*source = temp;
}

void	push_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	push_element(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push_element(stack_a, stack_b);
	ft_putstr("pb\n");
}
