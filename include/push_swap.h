#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

// Circular Linked Lists
typedef struct s_stack
{
	long	nbr;
	long	index;
}	t_stack;

// Useful Functions
void	ft_error(void);
void	ft_free_tab(char **tab);
void	ft_free_stack(t_list **stack);
long	ft_atol(const char *str);
int		ft_find_biggest(t_list *stack);
t_list	*ft_init_stack_a(int argc, char **argv);
// Input check functions
int		ft_count_arg(char **argv);
int		ft_check_double(char **argv);
int		ft_check_nb(char *argv);
void	ft_check_input(int argc, char **argv);
// Sort functions
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort_radix(t_list **stack_a, t_list **stack_b);
void	ft_index_stack(t_list *stack);

// Operations functions

void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_stack_a(t_list **stack);
void	ft_reverse_rotate_stack_b(t_list **stack);
void	ft_reverse_rotate_stack_ab(t_list **stack_a, t_list **stack_b);
void	ft_rotate_stack_a(t_list **stack);
void	ft_rotate_stack_b(t_list **stack);
void	ft_rotate_stack_ab(t_list **stack_a, t_list **stack_b);
void	ft_swap_a(t_list **stack);
void	ft_swap_b(t_list **stack);
void	ft_swap_ab(t_list **stack_a, t_list **stack_b);

#endif
