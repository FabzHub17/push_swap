/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:13:22 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:13:26 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b);

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_b(a, b);
}

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_num;

	target_node = NULL;
	while (b)
	{
		best_match_num = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->num > b->num) && (current_a->num < best_match_num))
			{
				best_match_num = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_num == LONG_MAX)
			b->target_node = stack_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
