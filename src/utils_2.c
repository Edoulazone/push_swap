/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:17:58 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:40:06 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_sorting_algorithm(t_stack **stack_a, t_stack **stack_b,
		int stack_size)
{
	if (stack_size <= 1 || is_stack_sorted(*stack_a))
		return ;
	if (stack_size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_top_two(stack_a);
	}
	else if (stack_size == 3)
		sort_three_elements(stack_a);
	else if (stack_size <= 5)
		sort_small_stack_optimized(stack_a);
	else
		enhanced_sort_large_stack(stack_a, stack_b);
}

int	execute_push_swap_single_arg(int argc, char **args)
{
	int		arg_count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	arg_count = 0;
	if (!args || !args[1])
		handle_error_and_exit_simple(NULL, NULL);
	while (args[arg_count])
		arg_count++;
	argc = arg_count;
	if (!enhanced_validate_input(args))
		handle_error_and_exit(NULL, NULL, args);
	if (is_input_already_sorted(args))
	{
		free_string_array(args);
		return (0);
	}
	stack_b = NULL;
	stack_a = create_stack_from_args(argc, args);
	stack_size = get_stack_size(stack_a);
	optimized_assign_indices(stack_a);
	execute_sorting_algorithm(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_string_array(args);
	return (0);
}

int	execute_push_swap_multiple_args(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (!argv || !argv[1])
		exit(1);
	if (!enhanced_validate_input(argv))
		handle_error_and_exit_simple(NULL, NULL);
	if (is_input_already_sorted(argv))
		return (0);
	stack_b = NULL;
	stack_a = create_stack_from_args(argc, argv);
	stack_size = get_stack_size(stack_a);
	optimized_assign_indices(stack_a);
	execute_sorting_algorithm(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
