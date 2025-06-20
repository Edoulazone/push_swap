/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:02:25 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 18:02:27 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Remove consecutive duplicate swaps (sa + sa = nothing) */
void	remove_duplicate_swaps(t_op_list *list)
{
	t_op_node	*current;
	t_op_node	*prev;

	current = list->head;
	prev = NULL;
	while (current && current->next)
	{
		if ((ft_strcmp(current->operation, "sa") == 0
				&& ft_strcmp(current->next->operation, "sa") == 0)
			|| (ft_strcmp(current->operation, "sb") == 0
				&& ft_strcmp(current->next->operation, "sb") == 0))
		{
			remove_op_node(list, prev, current);
			if (prev && prev->next)
				remove_op_node(list, prev, prev->next);
			else if (list->head)
				remove_op_node(list, NULL, list->head);
			current = prev ? prev->next : list->head;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

/* Replace node operation and remove next node */
void	replace_and_remove_next(t_op_list *list, t_op_node *current,
	const char *new_op)
{
	t_op_node	*to_remove;

	to_remove = current->next;
	current->next = to_remove->next;
	if (to_remove == list->tail)
		list->tail = current;
	free(current->operation);
	current->operation = ft_strdup(new_op);
	free(to_remove->operation);
	free(to_remove);
	list->count--;
}

/* Combine simultaneous rotations (ra + rb = rr) */
void	combine_simultaneous_rotations(t_op_list *list)
{
	t_op_node	*current;

	current = list->head;
	while (current && current->next)
	{
		if (ft_strcmp(current->operation, "ra") == 0
			&& ft_strcmp(current->next->operation, "rb") == 0)
			replace_and_remove_next(list, current, "rr");
		else if (ft_strcmp(current->operation, "rb") == 0
			&& ft_strcmp(current->next->operation, "ra") == 0)
			replace_and_remove_next(list, current, "rr");
		else if (ft_strcmp(current->operation, "rra") == 0
			&& ft_strcmp(current->next->operation, "rrb") == 0)
			replace_and_remove_next(list, current, "rrr");
		else if (ft_strcmp(current->operation, "rrb") == 0
			&& ft_strcmp(current->next->operation, "rra") == 0)
			replace_and_remove_next(list, current, "rrr");
		else
			current = current->next;
	}
}

/* Apply all optimizations to the operation list */
void	apply_optimizations(t_op_list *list)
{
	if (!list)
		return ;
	remove_duplicate_swaps(list);
	combine_simultaneous_rotations(list);
}

/* Print all operations in the list */
void	print_op_list(t_op_list *list)
{
	t_op_node	*current;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		ft_putstr(current->operation);
		ft_putstr("\n");
		current = current->next;
	}
}

/* Count consecutive operations of the same type */
int	count_consecutive_ops(t_op_node *start, const char *op_type)
{
	int			count;
	t_op_node	*current;

	count = 0;
	current = start;
	while (current && ft_strcmp(current->operation, op_type) == 0)
	{
		count++;
		current = current->next;
	}
	return (count);
}
