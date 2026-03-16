/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:12:59 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:13:01 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_target_a(t_stack *a, t_stack *b);
static void	calculate_cost_a(t_stack *a, t_stack *b);
static void	set_cheapest(t_stack *stack);

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_a(a, b);
	calculate_cost_a(a, b);
	set_cheapest(a);
}

void	set_index_and_median(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->pos_index = i;
		if (i <= median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_num;

	target_node = NULL;
	while (a)
	{
		best_match_num = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if ((current_b->num < a->num) && (current_b->num > best_match_num))
			{
				best_match_num = current_b->num;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_num == LONG_MIN)
			a->target_node = stack_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	calculate_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->pos_index;
		if (!(a->is_above_median))
			a->push_cost = len_a - (a->pos_index);
		if (a->target_node->is_above_median)
			a->push_cost += a->target_node->pos_index;
		else
			a->push_cost += len_b - (a->target_node->pos_index);
		a = a->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_cost;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_cost)
		{
			cheapest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}
