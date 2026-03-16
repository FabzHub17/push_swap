/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:18:44 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:18:46 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				pos_index;
	int				push_cost;
	bool			is_above_median;
	bool			is_cheapest;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

//UTILS
char				**init_args(int ac, char **av);
long				ft_atol(const char *s);
int					ft_isdigit(int c);
char				*ft_strchr(const char *str, int c);

// STACK UTILS
void				stack_init(t_stack **stack, char **array_num);
bool				is_stack_sorted(t_stack *stack);
int					stack_len(t_stack *stack);
int					find_min_position(t_stack *stack);
int					find_max_position(t_stack *stack);
t_stack				*stack_cheapest_node(t_stack *stack);
t_stack				*stack_min_node(t_stack *stack);
t_stack				*stack_max_node(t_stack *stack);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_name);

// STACK OPERATIONS
void				stack_sort(t_stack **a, t_stack **b);

// HANDLE ERRORS
int					error_syntax(char *str_n);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **a);
int					error_duplicate(t_stack *a, int n);
void				free_args(char **array_num, int ac, char **av);

// OPERATIONS
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// SORTING ALGORITHMS
void				sort_three(t_stack **a);
void				sort_small(t_stack **a, t_stack **b);
void				sort_turkish(t_stack **a, t_stack **b);

void				set_index_and_median(t_stack *stack);
void				init_nodes_a(t_stack *a, t_stack *b);
void				init_nodes_b(t_stack *a, t_stack *b);
void				rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				rev_rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);

#endif
