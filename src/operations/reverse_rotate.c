/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:17:27 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:17:29 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	second_last = NULL;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack **a)
{
	if (reverse_rotate_stack(a))
		ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (reverse_rotate_stack(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = reverse_rotate_stack(a);
	rotated_b = reverse_rotate_stack(b);
	if (rotated_a || rotated_b)
		ft_printf("rrr\n");
}
