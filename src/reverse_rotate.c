#include "push_swap.h"

static void    ft_reverse_rotate_stack(t_list  **stack)
{
    t_list  *previous;
    t_list  *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    previous = *stack;
    while (previous->next->next)
        previous = previous->next;
    last = previous->next;
    previous->next = NULL;
    last->next = *stack;
    *stack = last;
}

void    ft_reverse_rotate_stack_a(t_list **stack)
{
    ft_reverse_rotate_stack(stack);
    write(1, "rra\n", 4);
}

void    ft_reverse_rotate_stack_b(t_list **stack)
{
    ft_reverse_rotate_stack(stack);
    write(1, "rrb\n", 4);
}

void    ft_reverse_rotate_stack_ab(t_list **stack_a, t_list **stack_b)
{
    ft_reverse_rotate_stack(stack_a);
    ft_reverse_rotate_stack(stack_b);
    write(1, "rrr\n", 4);
}