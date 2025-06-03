#include "../includes/push_swap.h"

void	free_errors(t_stack **a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}