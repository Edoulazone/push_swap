/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:05:33 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 18:05:35 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Optimized sort_two function */
void	optimized_sort_two(t_stack **stack_a, t_op_list *ops)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		optimized_sa(stack_a, ops);
}

/* Optimized sort_three function */
void	optimized_sort_three(t_stack **stack_a, t_op_list *ops)
{
	int	highest_index;

	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	highest_index = find_highest_index(*stack_a);
	if ((*stack_a)->index == highest_index)
		optimized_ra(stack_a, ops);
	else if ((*stack_a)->next->index == highest_index)
		optimized_rra(stack_a, ops);
	if ((*stack_a)->value > (*stack_a)->next->value)
		optimized_sa(stack_a, ops);
}

/* Optimized push elements to stack B */
void	optimized_push_to_b(t_stack **stack_a, t_stack **stack_b,
	t_op_list *ops)
{
	int	total_size;
	int	elements_pushed;
	int	rotation_count;
	int	target_push_count;

	total_size = get_stack_size(*stack_a);
	target_push_count = total_size / 2;
	elements_pushed = 0;
	rotation_count = 0;
	while (total_size > 6 && rotation_count < total_size
		&& elements_pushed < target_push_count)
	{
		if ((*stack_a)->index <= total_size / 2)
		{
			optimized_pb(stack_a, stack_b, ops);
			elements_pushed++;
		}
		else
			optimized_ra(stack_a, ops);
		rotation_count++;
	}
	while (total_size - elements_pushed > 3)
	{
		optimized_pb(stack_a, stack_b, ops);
		elements_pushed++;
	}
}

/* Optimized sort remaining elements */
void	optimized_sort_remaining(t_stack **stack_a, t_op_list *ops)
{
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	if (stack_size == 2)
		optimized_sort_two(stack_a, ops);
	else if (stack_size == 3)
		optimized_sort_three(stack_a, ops);
}

/* Optimized execute move with cost calculation */
void	optimized_execute_move_with_costs(t_stack **stack_a,
	t_stack **stack_b, int cost_a, int cost_b, t_op_list *ops)
{
	while (cost_a > 0 && cost_b > 0)
	{
		optimized_ra(stack_a, ops);
		optimized_rb(stack_b, ops);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		optimized_rra(stack_a, ops);
		optimized_rrb(stack_b, ops);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		optimized_ra(stack_a, ops);
		cost_a--;
	}
	while (cost_a < 0)
	{
		optimized_rra(stack_a, ops);
		cost_a++;
	}
	while (cost_b > 0)
	{
		optimized_rb(stack_b, ops);
		cost_b--;
	}
	while (cost_b < 0)
	{
		optimized_rrb(stack_b, ops);
		cost_b++;
	}
	optimized_pa(stack_a, stack_b, ops);
}

/* Optimized cheapest move execution */
void	optimized_execute_cheapest(t_stack **stack_a, t_stack **stack_b,
	t_op_list *ops)
{
	t_stack	*current_b;
	t_stack	*cheapest;
	int		lowest_cost;
	int		current_cost;

	if (!stack_b || !*stack_b)
		return ;
	current_b = *stack_b;
	cheapest = current_b;
	lowest_cost = INT_MAX;
	while (current_b)
	{
		current_cost = nb_abs(current_b->cost_a) + nb_abs(current_b->cost_b);
		if (current_cost < lowest_cost)
		{
			lowest_cost = current_cost;
			cheapest = current_b;
		}
		current_b = current_b->next;
	}
	optimized_execute_move_with_costs(stack_a, stack_b, cheapest->cost_a,
		cheapest->cost_b, ops);
}

/* Optimized position stack minimum */
void	optimized_position_min(t_stack **stack_a, t_op_list *ops)
{
	int	lowest_position;
	int	stack_size;

	if (is_sorted(*stack_a))
		return ;
	stack_size = get_stack_size(*stack_a);
	lowest_position = get_lowest_index_position(stack_a);
	if (lowest_position > stack_size / 2)
	{
		while (lowest_position < stack_size)
		{
			optimized_rra(stack_a, ops);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			optimized_ra(stack_a, ops);
			lowest_position--;
		}
	}
}

/* Main optimized execute sort function */
void	optimized_execute_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_op_list	*ops;
	int			stack_size;

	if (!stack_a || !*stack_a)
		return ;
	stack_size = get_stack_size(*stack_a);
	ops = init_op_list();
	if (!ops)
		return ;
	if (stack_size == 2)
		optimized_sort_two(stack_a, ops);
	else if (stack_size == 3)
		optimized_sort_three(stack_a, ops);
	else if (stack_size > 3 && !is_sorted(*stack_a))
	{
		optimized_push_to_b(stack_a, stack_b, ops);
		optimized_sort_remaining(stack_a, ops);
		while (*stack_b)
		{
			set_target_positions(stack_a, stack_b);
			calculate_move_costs(stack_a, stack_b);
			optimized_execute_cheapest(stack_a, stack_b, ops);
		}
		optimized_position_min(stack_a, ops);
	}
	apply_optimizations(ops);
	print_op_list(ops);
	free_op_list(ops);
}
