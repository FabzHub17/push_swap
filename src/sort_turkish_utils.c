/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turkish_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:13:43 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:13:47 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b != cheapest_node->target_node) && (*a != cheapest_node))
		rr(a, b);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b != cheapest_node->target_node) && (*a != cheapest_node))
		rrr(a, b);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->is_above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->is_above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
