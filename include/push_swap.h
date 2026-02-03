#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

// Circular Linked Lists

typedef struct s_stack
{
    long    nbr;
    long    index;
}   t_stack;

// Useful Functions
void    ft_error(void);
void    ft_free_tab(char **tab);
void    ft_free_stack(t_list **stack);
t_list *ft_init_stack_a(int argc, char **argv);

// Input check functions
int	    ft_count_arg(char **argv);
int     ft_check_double(char **argv);
int     ft_check_nb(char *argv);
void    ft_check_input(int argc, char **argv);