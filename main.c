#include "push_swap.h"

static void initStackA(t_list **stack, int argc, char **argv)
{
    t_list  *new;
    char    **arguments;
    int     i;

    i = 0;
    if (argc == 2)
        arguments = ft_split(argv[1], ' ');
    else
    {
        i =1;
        arguments = argv
    }
    while (arguments[i])
    {
        new = ft_lstnew(ft_atoi(arguments[i]));
        ft_lstadd_back(stack, new);
        i++;
    }
    
}
int main(int argc, char **argv)
{
    t_list  **stack_a;
    t_list  **stack_b;

    if (argc < 2)
        return (-1);
}