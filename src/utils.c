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

static t_list   *ft_create_node(char *str, t_list *stack)
{
    t_stack *element;
    t_list  *new;

    element = malloc(sizeof(t_stack));
    if (!element)
    {
        ft_free_stack(&stack);
        ft_error();
    }
    element->nbr = ft_atoi(str);
    element->index = -1;
    new = ft_lstnew(element);
    if (!new)
    {
        free(element);
        ft_free_stack(&stack);
        ft_error();
    }
    return (new);
}

static t_list   *ft_init_from_string(char *str)
{
    char    **tmp;
    t_list  *stack;
    int     i;

    tmp = ft_split(str, ' ');
    if (!tmp)
        ft_error();
    i = 0;
    stack = NULL;

    while (tmp[i])
    {
        ft_lstadd_back(&stack, ft_create_node(tmp[i], stack));
        i++;
    }
    ft_free_tab(tmp);
    return (stack);
}

static t_list   *ft_init_from_args(char **argv)
{
    t_list  *stack;
    int     i;

    i = 0;
    stack = NULL;
    while (argv[i])
    {
        ft_lstadd_back(&stack, ft_create_node(argv[i], stack));
        i++;
    }
    return (stack);
}

t_list *ft_init_stack_a(int argc, char **argv)
{
    if (argc == 2)
        return (ft_init_from_string(argv[1]));
    else
        return (ft_init_from_args(argv + 1));
}