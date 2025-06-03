/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvithara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:46:03 by tvithara          #+#    #+#             */
/*   Updated: 2025/05/15 16:46:17 by tvithara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_stack *a; // stores pointer to stack a
    t_stack *b; // stores pointer to stack b
    char **num_array;

    a = NULL;
    b = NULL;
    if( ac == 1 || (ac == 2 && !av[1][0]) ) // Check for empty input
        return (1); // 1 because to indicate an error in input
    num_array = init_args(&a,ac,av); // make a char** array of the numbers
    init_stack_a(&a, num_array); // Initialize stack a with the arguments
    if(!is_stack_sorted(a))
        sort_stacks(&a,&b);
    free_stacks(&a);
    return (0);
}



