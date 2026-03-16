/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:16:52 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:16:54 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**init_args(int ac, char **av)
{
	char	**nums_array;

	nums_array = NULL;
	if (ac == 2)
	{
		if (ft_strchr(av[1], ' '))
		{
			nums_array = ft_split(av[1], ' ');
			if (!nums_array)
				return (NULL);
		}
		else
			nums_array = av + 1;
	}
	else
		nums_array = av + 1;
	return (nums_array);
}

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

bool	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
