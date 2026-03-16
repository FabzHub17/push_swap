/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:15:43 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:15:46 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insert_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*current_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		free_errors(stack);
	new_node->num = n;
	new_node->pos_index = 0;
	new_node->is_above_median = false;
	new_node->is_cheapest = false;
	new_node->next = NULL;
	new_node->target_node = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current_node = *stack;
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = new_node;
	}
}

void	stack_init(t_stack **stack, char **array_nums)
{
	long	n;
	int		i;

	if (!(*array_nums))
		free_errors(stack);
	i = 0;
	while (array_nums[i] != NULL)
	{
		if (error_syntax(array_nums[i]))
			free_errors(stack);
		n = ft_atol(array_nums[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(stack);
		if (error_duplicate(*stack, (int)n))
			free_errors(stack);
		insert_node(stack, (int)n);
		i++;
	}
	if (!(*stack))
		free_errors(stack);
}
