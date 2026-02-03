#include "push_swap.h"

static void    ft_push(t_list **stack_from, t_list **stack_to)
{
    t_list  *tmp;

    if (!stack_from|| !*stack_from)
        return ;
    tmp = *stack_from;
    *stack_from = (*stack_from)->next;
    tmp->next = *stack_to;
    *stack_to = tmp;
}

void    ft_push_a(t_list **stack_a, t_list **stack_b)
{
    ft_push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void    ft_push_b(t_list **stack_a, t_list **stack_b)
{
    ft_push(stack_a, stack_b);
    write(1, "pb\n", 3);
}