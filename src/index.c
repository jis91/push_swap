#include "push_swap.h"

static int     ft_find_min(t_list *stack)
{
    int     min;
    t_stack *data;

    min = INT_MAX;
    while (stack)
    {
        data = (t_stack *)(stack->content);
        if(data->index == -1 && data->nbr < min)
            min = data->nbr;
        stack = stack->next;
    }
    return (min);
}

static void    ft_assign_index(t_list *stack, int index, int number)
{
    t_stack *data;
    while (stack)
    {
        data = (t_stack *)(stack->content);
        if (data->nbr == number && data->index == -1)
        {
            data->index = index;
            return ;
        }
        stack = stack->next;
    }
}

void    ft_index_stack(t_list *stack)
{
    int     size;
    int     min;
    int     i;

    size = ft_lstsize(stack);
    i = 0;
    while (i < size)
    {
        min = ft_find_min(stack);
        ft_assign_index(stack, i, min);
        i++;
    }
}