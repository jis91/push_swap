#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    stack_a = ft_init_stack_a(argc, argv);
    if (!a || ft_check_duplicate(a))
    {
        ft_free(&a);
        ft_error();
    }
    if (!ft_check_sorted(a))
        ft_sort(&a);
    ft_free(&a);
    return (0);
}