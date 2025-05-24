#include "../includes/push_swap.h"

void init_stack(t_stack **stack, char **args)
{
    t_stack *new_node;
    t_stack *temp;
    int i;

    i = 0;
    while (args[i])
    {
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return ;
        new_node->value = atoi(args[i]);
        new_node->index = i; // Assign index based on the order of input
        new_node->next = NULL;
        if (*stack == NULL)
            *stack = new_node;
        else
        {
            temp = *stack;
            while (temp->next)
                temp = temp->next;
            temp->next = new_node;
        }
        i++;
    }
}