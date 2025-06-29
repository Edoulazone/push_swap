/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:31:16 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:07:13 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b)
{
	stack_clear(stack_a);
	stack_clear(stack_b);
	error_exit();
}

static int	initialize_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = stack_init();
	*stack_b = stack_init();
	if (!*stack_a || !*stack_b)
		return (0);
	return (1);
}

static void	process_and_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
	{
		stack_clear(stack_a);
		stack_clear(stack_b);
		return ;
	}
	assign_indices(stack_a);
	sort_stack(stack_a, stack_b);
	stack_clear(stack_a);
	stack_clear(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!initialize_stacks(&stack_a, &stack_b))
		error_exit();
	if (!parse_arguments(argc, argv, stack_a))
		cleanup_and_exit(stack_a, stack_b);
	process_and_sort(stack_a, stack_b);
	return (0);
}
