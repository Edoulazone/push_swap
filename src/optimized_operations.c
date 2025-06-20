/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:05:51 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 18:05:53 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Optimized swap operations */
void	optimized_sa(t_stack **stack_a, t_op_list *ops)
{
	t_stack	*first;
	t_stack	*second;
	int		temp_value;
	int		temp_index;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	temp_value = first->value;
	first->value = second->value;
	second->value = temp_value;
	temp_index = first->index;
	first->index = second->index;
	second->index = temp_index;
	if (ops)
		add_operation_to_list(&ops, "sa");
	else
		ft_putstr("sa\n");
}

void	optimized_sb(t_stack **stack_b, t_op_list *ops)
{
	t_stack	*first;
	t_stack	*second;
	int		temp_value;
	int		temp_index;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	temp_value = first->value;
	first->value = second->value;
	second->value = temp_value;
	temp_index = first->index;
	first->index = second->index;
	second->index = temp_index;
	if (ops)
		add_operation_to_list(&ops, "sb");
	else
		ft_putstr("sb\n");
}

/* Optimized push operations */
void	optimized_pa(t_stack **stack_a, t_stack **stack_b, t_op_list *ops)
{
	t_stack	*node_to_move;

	if (!stack_b || !*stack_b)
		return ;
	node_to_move = *stack_b;
	*stack_b = (*stack_b)->next;
	node_to_move->next = *stack_a;
	*stack_a = node_to_move;
	if (ops)
		add_operation_to_list(&ops, "pa");
	else
		ft_putstr("pa\n");
}

void	optimized_pb(t_stack **stack_a, t_stack **stack_b, t_op_list *ops)
{
	t_stack	*node_to_move;

	if (!stack_a || !*stack_a)
		return ;
	node_to_move = *stack_a;
	*stack_a = (*stack_a)->next;
	node_to_move->next = *stack_b;
	*stack_b = node_to_move;
	if (ops)
		add_operation_to_list(&ops, "pb");
	else
		ft_putstr("pb\n");
}

/* Optimized rotation operations */
void	optimized_ra(t_stack **stack_a, t_op_list *ops)
{
	t_stack	*first;
	t_stack	*bottom;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	bottom = get_stack_bottom(*stack_a);
	first->next = NULL;
	bottom->next = first;
	if (ops)
		add_operation_to_list(&ops, "ra");
	else
		ft_putstr("ra\n");
}

void	optimized_rb(t_stack **stack_b, t_op_list *ops)
{
	t_stack	*first;
	t_stack	*bottom;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	bottom = get_stack_bottom(*stack_b);
	first->next = NULL;
	bottom->next = first;
	if (ops)
		add_operation_to_list(&ops, "rb");
	else
		ft_putstr("rb\n");
}

/* Optimized reverse rotation operations */
void	optimized_rra(t_stack **stack_a, t_op_list *ops)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	bottom = get_stack_bottom(*stack_a);
	before_bottom = get_stack_before_bottom(*stack_a);
	before_bottom->next = NULL;
	bottom->next = *stack_a;
	*stack_a = bottom;
	if (ops)
		add_operation_to_list(&ops, "rra");
	else
		ft_putstr("rra\n");
}

void	optimized_rrb(t_stack **stack_b, t_op_list *ops)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	bottom = get_stack_bottom(*stack_b);
	before_bottom = get_stack_before_bottom(*stack_b);
	before_bottom->next = NULL;
	bottom->next = *stack_b;
	*stack_b = bottom;
	if (ops)
		add_operation_to_list(&ops, "rrb");
	else
		ft_putstr("rrb\n");
}
