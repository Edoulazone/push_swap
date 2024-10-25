/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:17:58 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/03 15:28:45 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	exit_error_argv(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

int	do_this_shit(int argc, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	i = 0;
	if (!av || !av[1])
		exit_error_argv(NULL, NULL);
	while (av[i])
		i++;
	argc = i;
	if (!is_correct_input(av))
		exit_error(NULL, NULL, av);
	stack_b = NULL;
	stack_a = fill_stack_values(argc, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_tab(av);
	return (0);
}

int	do_this_other_shit(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (!argv || !argv[1])
		exit(1);
	if (!is_correct_input(argv))
		exit_error_argv(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(argc, argv);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
