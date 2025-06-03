#include "../includes/push_swap.h"

static void inser_node(t_stack **stack, int n);

void init_stack(t_stack **stack, char **array_num)
{
    long n;
    int i;

    i = 0;
    while(array_num[i])
    {
        n = ft_atol(array_num[i]);
        if(n > INT_MAX || n < INT_MIN)
            free_errors(stack); // Check for integer overflow
        insert_node(stack, (int)n); //If no errors, append the node to the linked list by, taking a pointer to stack `a`, create a new node and assign `n` to that new node
        i++;
    }
}



static void inser_node(t_stack **stack, int n)
{
    t_stack *new_node;
    t_stack *current_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        free_errors(stack); // Check for memory allocation failure
    new_node->value = n;
    new_node->index = 0; // Initialize index to 0
    new_node->next = NULL;

    if (*stack == NULL) // If the stack is empty, set the new node as the head
    {
        *stack = new_node;
        new_node->prev = NULL;
        return;
    }

    current_node = *stack;
    while (current_node->next) // Traverse to the end of the stack
        current_node = current_node->next;
    
    current_node->next = new_node; // Append the new node at the end
    new_node->prev = current_node;
}

int is_stack_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value) // Check if the current value is greater than the next value
            return (0); // Stack is not sorted
        stack = stack->next;
    }
    return (1); // Stack is sorted
}