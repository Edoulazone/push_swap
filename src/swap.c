/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:20:51 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:27:51 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top_elements(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	swap_top_two(t_stack **stack_a)
{
	swap_top_elements(*stack_a);
	ft_putstr("sa\n");
}

void	swap_stack_b(t_stack **stack_b)
{
	swap_top_elements(*stack_b);
	ft_putstr("sb\n");
}

void	swap_both_stacks(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_elements(*stack_a);
	swap_top_elements(*stack_b);
	ft_putstr("ss\n");
}
