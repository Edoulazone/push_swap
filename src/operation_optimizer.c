/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_optimizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:59:53 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 18:01:48 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* String comparison function for operation names */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* String duplication function */
char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* Create a new operation node */
t_op_node	*create_op_node(const char *operation)
{
	t_op_node	*new_node;

	new_node = malloc(sizeof(t_op_node));
	if (!new_node)
		return (NULL);
	new_node->operation = ft_strdup(operation);
	if (!new_node->operation)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

/* Add operation to the end of the list */
void	add_operation_to_list(t_op_list **list, const char *operation)
{
	t_op_node	*new_node;
	t_op_node	*current;

	new_node = create_op_node(operation);
	if (!new_node)
		return ;
	if (!(*list)->head)
	{
		(*list)->head = new_node;
		(*list)->tail = new_node;
	}
	else
	{
		(*list)->tail->next = new_node;
		(*list)->tail = new_node;
	}
	(*list)->count++;
}

/* Remove operation node and free memory */
void	remove_op_node(t_op_list *list, t_op_node *prev, t_op_node *to_remove)
{
	if (prev)
		prev->next = to_remove->next;
	else
		list->head = to_remove->next;
	if (to_remove == list->tail)
		list->tail = prev;
	free(to_remove->operation);
	free(to_remove);
	list->count--;
}

/* Initialize operation list */
t_op_list	*init_op_list(void)
{
	t_op_list	*list;

	list = malloc(sizeof(t_op_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	return (list);
}

/* Free entire operation list */
void	free_op_list(t_op_list *list)
{
	t_op_node	*current;
	t_op_node	*next;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		next = current->next;
		free(current->operation);
		free(current);
		current = next;
	}
	free(list);
}
