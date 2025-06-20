/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:18:32 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 18:06:07 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Stack initialization and setup */
t_stack		*create_stack_from_args(int argc, char **argv);
void		optimized_assign_indices(t_stack *stack_a);

/* Sorting algorithms */
int			is_stack_sorted(t_stack *stack);
void		sort_three_elements(t_stack **stack);
void		enhanced_sort_large_stack(t_stack **stack_a, t_stack **stack_b);
void		sort_small_stack_optimized(t_stack **stack_a);

/* Position and target calculations */
int			find_smallest_element_position(t_stack **stack);
void		calculate_target_positions(t_stack **stack_a, t_stack **stack_b);

/* Cost calculation and move execution */
void		enhanced_calculate_costs(t_stack **stack_a, t_stack **stack_b);
void		find_optimal_move(t_stack **stack_a, t_stack **stack_b);
void		execute_move_sequence(t_stack **a, t_stack **b, int cost_a,
				int cost_b);

/* Stack operations - Push */
void		push_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void		push_to_stack_b(t_stack **stack_a, t_stack **stack_b);

/* Stack operations - Swap */
void		swap_top_two(t_stack **stack_a);
void		swap_stack_b(t_stack **stack_b);
void		swap_both_stacks(t_stack **stack_a, t_stack **stack_b);

/* Stack operations - Rotate */
void		rotate_stack_a_up(t_stack **stack_a);
void		rotate_stack_b_up(t_stack **stack_b);
void		rotate_both_stacks_up(t_stack **stack_a, t_stack **stack_b);

/* Stack operations - Reverse rotate */
void		rotate_stack_a_down(t_stack **stack_a);
void		rotate_stack_b_down(t_stack **stack_b);
void		rotate_both_stacks_down(t_stack **stack_a, t_stack **stack_b);

/* Stack management utilities */
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*create_new_stack_node(int value);
void		add_node_to_stack_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* Memory management and error handling */
void		free_stack(t_stack **stack);
void		handle_error_and_exit(t_stack **stack_a, t_stack **stack_b,
				char **args);
void		handle_error_and_exit_simple(t_stack **stack_a, t_stack **stack_b);

/* Input validation */
int			enhanced_validate_input(char **argv);
int			is_input_already_sorted(char **argv);
int			is_digit(char c);
int			is_sign(char c);

/* Utility functions */
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			get_absolute_value(int nb);
int			ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);

/* Main execution functions */
int			execute_push_swap_single_arg(int argc, char **args);
int			execute_push_swap_multiple_args(int argc, char **argv);
void		free_string_array(char **array);

/* String splitting utility */
char		**ft_split(char *s, char c);

/* Enhanced sorting strategies */
void    enhanced_push_elements_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void    chunked_distribution(t_stack **stack_a, t_stack **stack_b);
void    adaptive_distribution(t_stack **stack_a, t_stack **stack_b);
int     find_longest_increasing_subsequence(t_stack *stack);

/* Enhanced cost analysis */
void    enhanced_calculate_move_costs(t_stack **stack_a, t_stack **stack_b);
void    enhanced_execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);
int     find_enhanced_target_position(t_stack **stack_a, int b_index);

/* Adaptive sorting */
void    adaptive_execute_sort(t_stack **stack_a, t_stack **stack_b);

/* Testing functions */
void    compare_strategies(t_stack *test_stack);
void    run_comprehensive_tests(void);
t_stack *generate_random_stack(int size);
t_stack *copy_stack(t_stack *original);

/* ========== OPERATION OPTIMIZER STRUCTURES ========== */

/* Operation list node for recording operations */
typedef struct s_op_node
{
	char				*operation;
	struct s_op_node	*next;
}	t_op_node;

/* ========== OPERATION OPTIMIZER FUNCTIONS ========== */

/* Core optimization functions */
void    enable_optimization_mode(void);
void    disable_optimization_mode(void);
void    record_operation(const char *op);
void    optimized_ft_putstr(const char *str);
void    output_optimized_operations(int stack_size_a, int stack_size_b);
void    free_operation_list(void);

/* String utility functions for optimizer */
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *s);

/* Optimization utility functions */
int     count_consecutive_ops(t_op_node *start, const char *op_type);
void    remove_duplicate_swaps(void);
void    combine_simultaneous_rotations(void);
void    apply_optimizations(int stack_size_a, int stack_size_b);

/* Optimized stack operations */
void    optimized_sa(t_stack **stack_a);
void    optimized_sb(t_stack **stack_b);
void    optimized_pa(t_stack **stack_a, t_stack **stack_b);
void    optimized_pb(t_stack **stack_a, t_stack **stack_b);
void    optimized_ra(t_stack **stack_a);
void    optimized_rb(t_stack **stack_b);
void    optimized_rra(t_stack **stack_a);
void    optimized_rrb(t_stack **stack_b);

/* Optimized sorting functions */
void    optimized_execute_sort(t_stack **stack_a, t_stack **stack_b);
void    optimized_sort_two(t_stack **stack_a);
void    optimized_sort_three(t_stack **stack_a);
void    optimized_push_elements_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void    optimized_sort_remaining_elements(t_stack **stack_a);
void    optimized_optimize_stack_placement(t_stack **stack_a, t_stack **stack_b);
void    optimized_execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void    optimized_execute_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
void    optimized_rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);
void    optimized_reverse_rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);
void    optimized_rotate_stack_to_position(t_stack **stack, int *cost, 
                                          void (*rotate)(t_stack**), 
                                          void (*reverse_rotate)(t_stack**));
void    optimized_position_stack_minimum(t_stack **stack_a);

#endif