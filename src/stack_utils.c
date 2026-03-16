/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:16:26 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:16:28 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_max_node(t_stack *stack)
{
	t_stack	*max_node;
	long	max_num;

	if (!stack)
		return (NULL);
	max_node = NULL;
	max_num = LONG_MIN;
	while (stack)
	{
		if (stack->num > max_num)
		{
			max_num = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*stack_min_node(t_stack *stack)
{
	t_stack	*min_node;
	long	min_num;

	if (!stack)
		return (NULL);
	min_node = NULL;
	min_num = LONG_MAX;
	while (stack)
	{
		if (stack->num < min_num)
		{
			min_num = stack->num;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	find_min_position(t_stack *stack)
{
	int	min_num;
	int	min_pos;
	int	current_pos;

	if (!stack)
		return (0);
	min_num = stack->num;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->num < min_num)
		{
			min_num = stack->num;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

int	find_max_position(t_stack *stack)
{
	int	max_value;
	int	max_pos;
	int	current_pos;

	max_pos = 0;
	current_pos = 0;
	if (!stack)
		return (-1);
	max_value = stack->num;
	while (stack)
	{
		if (stack->num > max_value)
		{
			max_value = stack->num;
			max_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (max_pos);
}

t_stack	*stack_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
