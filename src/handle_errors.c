/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:12:19 by tvithara          #+#    #+#             */
/*   Updated: 2025/06/16 19:12:27 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_syntax(char *str_n)
{
	if (*str_n == '+' || *str_n == '-')
	{
		if (!ft_isdigit(str_n[1]))
			return (1);
		str_n++;
	}
	while (*str_n)
	{
		if (!(ft_isdigit(*str_n)))
			return (1);
		str_n++;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}

int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_args(char **array_num, int ac, char **av)
{
	char	**ptr;

	ptr = array_num;
	if (ac == 2 && ft_strchr(av[1], ' '))
	{
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(array_num);
	}
}
