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
    t_stack *a;
    t_stack *b;
    char **num_array;

    a = NULL;
    b = NULL;
    if( ac == 1 || (ac == 2 && !av[1][0]) ) // Check for empty input
        return (1);
    //if(ac < 2)
    //    return (1);
    //else if (ac == 2)
    //    num_array = ft_split(av[1], ' '); // Split the input string into arguments
    num_array = init_args(ac,av); 
    init_stack(&a, num_array); // Initialize stack a with the arguments
    return (0);
}


