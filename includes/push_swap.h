/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:49:54 by tvithara          #+#    #+#             */
/*   Updated: 2025/05/15 17:19:31 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

//Utils
static long	ft_atol(const char *s);

// Stack Utils
void init_stack(t_stack **stack, char **array_num);
int is_stack_sorted(t_stack *stack);

// Handle Errors
void	free_errors(t_stack **a);
#endif

