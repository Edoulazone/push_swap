/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_optimization_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:36:00 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:36:09 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_batch_cost(t_stack *a, t_stack *b, t_node **batch,
		int size)
{
	int	total_cost;
	int	i;
	int	individual_cost;

	if (!batch || size <= 0)
		return (INT_MAX);
	total_cost = 0;
	i = 0;
	while (i < size)
	{
		if (!batch[i])
			return (INT_MAX);
		individual_cost = simulate_move_cost(a, b, batch[i]);
		if (individual_cost == INT_MAX)
			return (INT_MAX);
		total_cost += individual_cost;
		i++;
	}
	return (total_cost);
}

static void	update_best_batch(t_node **best_batch, int *best_size,
		t_node **batch, int batch_size)
{
	int	i;

	*best_size = batch_size;
	i = 0;
	while (i < batch_size)
	{
		best_batch[i] = batch[i];
		i++;
	}
}

static void	find_optimal_batch_helper(t_stack *a, t_stack *b, t_node *current,
		t_node **best_batch, int *best_size, int *best_cost)
{
	t_node	*batch[4];
	int		batch_size;
	int		current_cost;

	batch[0] = current;
	batch_size = 1;
	while (batch_size < 4 && batch[batch_size - 1]->next)
	{
		batch[batch_size] = batch[batch_size - 1]->next;
		batch_size++;
		current_cost = calculate_batch_cost(a, b, batch, batch_size);
		if (current_cost < *best_cost)
		{
			*best_cost = current_cost;
			update_best_batch(best_batch, best_size, batch, batch_size);
		}
	}
}

static void	find_optimal_batch(t_stack *a, t_stack *b, t_node **best_batch,
		int *best_size)
{
	t_node	*current;
	int		best_cost;

	*best_size = 1;
	best_batch[0] = find_cheapest(b);
	best_cost = best_batch[0]->push_cost;
	current = b->top;
	while (current && current->next)
	{
		find_optimal_batch_helper(a, b, current, best_batch, best_size,
			&best_cost);
		current = current->next;
	}
}

void	execute_optimized_moves(t_stack *a, t_stack *b)
{
	t_node	*best_batch[4];
	int		best_size;
	int		i;

	find_optimal_batch(a, b, best_batch, &best_size);
	i = 0;
	while (i < best_size)
	{
		execute_move(a, b, best_batch[i]);
		i++;
	}
}
