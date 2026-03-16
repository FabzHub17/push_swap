/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turkish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:14:04 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:14:06 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_a_to_b(t_stack **a, t_stack **b);
static void	move_b_to_a(t_stack **a, t_stack **b);
static void	min_on_top(t_stack **a);

void	sort_turkish(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(a, b);
	while ((len_a-- > 3) && (!is_stack_sorted(*a)))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index_and_median(*a);
	min_on_top(a);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	if (!a || !*a || !b)
		return ;
	cheapest_node = stack_cheapest_node(*a);
	if ((cheapest_node->is_above_median)
		&& (cheapest_node->target_node->is_above_median))
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->is_above_median)
		&& !(cheapest_node->target_node->is_above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	min_on_top(t_stack **a)
{
	while ((*a)->num != stack_min_node(*a)->num)
	{
		if (stack_min_node(*a)->is_above_median)
			ra(a);
		else
			rra(a);
	}
}
