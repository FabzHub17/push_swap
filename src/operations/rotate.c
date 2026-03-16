/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:17:39 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:17:41 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate_stack(a))
		ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (rotate_stack(b))
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_stack(a);
	rotated_b = rotate_stack(b);
	if (rotated_a || rotated_b)
		ft_printf("rr\n");
}
