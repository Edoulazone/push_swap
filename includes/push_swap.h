/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:18:32 by eschmitz          #+#    #+#             */
/*   Updated: 2025/06/12 17:31:54 by eschmitz         ###   ########.fr       */
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
void		assign_sorted_indices(t_stack *stack_a, int stack_size);

/* Sorting algorithms */
int			is_stack_sorted(t_stack *stack);
void		sort_three_elements(t_stack **stack);
void		sort_large_stack(t_stack **stack_a, t_stack **stack_b);

/* Position and target calculations */
int			find_smallest_element_position(t_stack **stack);
void		calculate_target_positions(t_stack **stack_a, t_stack **stack_b);

/* Cost calculation and move execution */
void		calculate_movement_costs(t_stack **stack_a, t_stack **stack_b);
void		execute_most_efficient_move(t_stack **stack_a, t_stack **stack_b);
void		execute_move_sequence(t_stack **a, t_stack **b, int cost_a, int cost_b);

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
void		handle_error_and_exit(t_stack **stack_a, t_stack **stack_b, char **args);
void		handle_error_and_exit_simple(t_stack **stack_a, t_stack **stack_b);

/* Input validation */
int			validate_input(char **argv);
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

#endif
