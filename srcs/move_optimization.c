/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:18:11 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/29 17:44:13 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	should_use_advanced_calculation(t_stack *b)
{
	if (!b || b->size < 3)
		return (0);
	if (b->size > 100)
		return (0);
	return (1);
}
