/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:16:11 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:16:13 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);

void	stack_sort(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !(*a) || is_stack_sorted(*a))
		return ;
	size = stack_len(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
		sort_turkish(a, b);
	return ;
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if ((first > second) && (second < third) && (first < third))
		sa(a);
	else if ((first > second) && (second > third))
	{
		sa(a);
		rra(a);
	}
	else if ((first > second) && (second < third) && (first > third))
		ra(a);
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(a);
		ra(a);
	}
	else if ((first < second) && (second > third) && (first > third))
		rra(a);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = 0;
	while (stack_len(*a) > 3)
	{
		min_pos = find_min_position(*a);
		if (min_pos <= stack_len(*a) / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			while (min_pos++ < stack_len(*a))
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
