# include "push_swap.h"

void    ft_swap(t_list  **stack)
{
    t_list  *tmp;

    if(!*stack || (*stack)->next == NULL)
        return ;
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
}

void    ft_swap_a(t_list **stack)
{
    ft_swap(stack);
    write(1, "sa\n", 3);
}

void    ft_swap_b(t_list **stack)
{
    ft_swap(stack);
    write(1, "sb\n", 3);
}

void    ft_swap_ab(t_list **stack_a, t_list **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    write(1, "ss\n", 3);
}