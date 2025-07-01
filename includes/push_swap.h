/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:18:32 by eschmitz          #+#    #+#             */
/*   Updated: 2025/07/01 15:44:53 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_batch_context
{
	t_stack	*a;
	t_stack	*b;
	t_node	**best_batch;
	int		*best_size;
	int		*best_cost;
}	t_batch_context;

/* Stack operations */
t_stack		*stack_init(void);
void		stack_push(t_stack *stack, t_node *node);
t_node		*stack_pop(t_stack *stack);
void		stack_clear(t_stack *stack);
t_node		*node_create(int value);

/* Basic operations */
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

/* Rotate operations */
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		rap(t_stack *a); //Rotate for parsing

/* Parsing */
int			parse_arguments(int argc, char **argv, t_stack *stack_a);
int			is_valid_number(char *str);
int			has_duplicates(t_stack *stack);

/* Utils */
void		error_exit(void);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
long		ft_atol(char *str);
void		free_split(char **split);
void		*ft_memcpy(void *dst, const void *src, size_t n);

/* Split */
char		**ft_split(char *s, char c);
int			word_count(char *s, char c);

/* Stack analysis */
int			is_sorted(t_stack *stack);
int			stack_min(t_stack *stack);
int			stack_max(t_stack *stack);
int			find_position(t_stack *stack, int value);
void		assign_indices(t_stack *stack);

/* Sorting */
void		sort_stack(t_stack *a, t_stack *b);
void		sort_three(t_stack *a);
void		sort_small(t_stack *a, t_stack *b);
void		sort_large_optimized(t_stack *a, t_stack *b);

/* Cost calculation */
void		set_targets(t_stack *a, t_stack *b);
int			rotation_cost(int position, int size);
void		calculate_costs(t_stack *a, t_stack *b);
t_node		*find_cheapest(t_stack *b);

/* Move execution */
void		rotate_to_position(t_stack *stack, int position, char stack_name);
void		execute_move(t_stack *a, t_stack *b, t_node *cheapest);
void		bring_min_to_top(t_stack *a);

/* Advanced cost */
int			simulate_move_cost(t_stack *a, t_stack *b, t_node *node);
void		calculate_advanced_costs(t_stack *a, t_stack *b, int lookahead);
int			calculate_combined_cost(int cost_a, int cost_b);

/* Pattern detection */
void		apply_pattern_optimization(t_stack *a, t_stack *b);
int			has_beneficial_pattern(t_stack *b);

/* Move optimization */
void		execute_optimized_moves(t_stack *a, t_stack *b);
int			should_use_advanced_calculation(t_stack *b);

#endif
