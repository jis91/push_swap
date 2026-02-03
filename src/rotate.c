# include "push_swap.h"

void    ft_rotate_stack(t_list **stack)
{
    t_list  *first;
    t_list  *last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    last = ft_lstlast(*stack);

    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void    ft_rotate_stack_a(t_list **stack)
{
    ft_rotate_stack(stack);
    write(1, "ra\n", 3);
}

void    ft_rotate_stack_b(t_list **stack)
{
    ft_rotate_stack(stack);
    write(1, "rb\n", 3);
}

void    ft_rotate_stack_ab(t_list **stack_a, t_list **stack_b)
{
    ft_rotate_stack(stack_a);
    ft_rotate_stack(stack_b);
    write(1, "rr\n", 3);
}