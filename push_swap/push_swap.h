/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:52:12 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/06 21:13:34 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;

}						t_stack_node;

// handle_errors.c
int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a);
// init_a_to_b.c
void					current_index(t_stack_node *stack);
void					set_target_a(t_stack_node *a, t_stack_node *b);
void					cost_analysis_a(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
// init_b_to_a.c
void					set_target_b(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
// push.c
void					push(t_stack_node **dst, t_stack_node **src);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
// rev_rotate.c
void					rev_rotate(t_stack_node **stack);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
// rotate.c
void					rotate(t_stack_node **stack);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
// sort_3.c
void					sort_3(t_stack_node **a);
// stack_init.c
long					ft_atol(const char *s);
void					append_node(t_stack_node **stack, int n);
void					init_stack_a(t_stack_node **a, char **argv);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
// stack_utils.c
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
// swap.c
void					swap(t_stack_node **head);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
// sort_stacks.c
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					move_a_to_b(t_stack_node **a, t_stack_node **b);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					min_on_top(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
char					*ft_joinchar(char *s1, char s2);
int						peasoifses(char **movements, t_stack_node **a,
							t_stack_node **b);
void					peasoifses2(char *move, t_stack_node **a,
							t_stack_node **b);

#endif
