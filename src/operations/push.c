/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:17:20 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:17:21 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src || !*src)
		return (0);
	temp = *src;
	*src = (*src)->next;
	if (!*dest)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest;
		*dest = temp;
	}
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push_stack(b, a))
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (push_stack(a, b))
		ft_printf("pb\n");
}
