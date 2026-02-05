#include "push_swap.h"

static int	ft_find_min_index(t_list *stack)
{
	t_list	*tmp;
	t_stack	*data;
	int		min;
	int		index;
	int		min_index;

	tmp = stack;
	data = (t_stack *)(tmp->content);
	min = data->nbr;
	index = 0;
	min_index = 0;
	while (tmp)
	{
		data = (t_stack *)(tmp->content);
		if (data->nbr < min)
		{
			min = data->nbr;
			min_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (min_index);
}

static int	ft_is_sorted(t_list *stack)
{
	t_list	*tmp;
	t_stack	*current;
	t_stack	*next_one;

	tmp = stack;
	while (tmp && tmp->next)
	{
		current = (t_stack *)(tmp->content);
		next_one = (t_stack *)(tmp->next->content);
		if (current->nbr > next_one->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_sort_three(t_list **stack)
{
	int		biggest;
	t_stack	*top;
	t_stack	*second;

	biggest = ft_find_biggest(*stack);
	top = (t_stack *)((*stack)->content);
	second = (t_stack *)((*stack)->next->content);
	if (top->nbr == biggest)
		ft_rotate_stack_a(stack);
	else if (second->nbr == biggest)
		ft_reverse_rotate_stack_a(stack);
	top = (t_stack *)((*stack)->content);
	second = (t_stack *)((*stack)->next->content);
	if (top->nbr > second->nbr)
		ft_swap_a(stack);
}

static void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		min_position;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		min_position = ft_find_min_index(*stack_a);
		if (min_position <= size / 2)
		{
			while (min_position--)
				ft_rotate_stack_a(stack_a);
		}
		else
		{
			while (min_position++ < size)
				ft_reverse_rotate_stack_a(stack_a);
		}
		ft_push_b(stack_a, stack_b);
		size--;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_push_a(stack_a, stack_b);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (ft_is_sorted(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_swap_a(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size <= 5)
		ft_sort_five(stack_a, stack_b);
	else
	{
		ft_index_stack(*stack_a);
		ft_sort_radix(stack_a, stack_b);
	}
}
