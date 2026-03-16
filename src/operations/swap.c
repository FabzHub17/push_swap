/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:17:48 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:17:51 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_stack **stack_a)
{
	if (swap_stack(stack_a))
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (swap_stack(stack_b))
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap_stack(stack_a);
	swapped_b = swap_stack(stack_b);
	if (swapped_a || swapped_b)
		ft_printf("ss\n");
}
