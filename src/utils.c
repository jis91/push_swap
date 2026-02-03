#include "push_swap.h"

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void    ft_free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}

void    ft_free_stack(t_list **stack)
{
    t_list  *tmp;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp->content);
        free(tmp);
    }
}

int     ft_find_biggest(t_list *stack)
{
    int     biggest;
    t_stack *data;

    biggest = INT_MIN;
    while (stack)
    {
        data = (t_stack *)(stack->content);
        if (data->nbr > biggest)
            biggest = data->nbr;
        stack = stack->next;
    }
    return (biggest);
}

