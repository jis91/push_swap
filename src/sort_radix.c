#include "push_swap.h"

static int	ft_find_max_index(t_list *stack)
{
	int		max;
	t_stack	*data;

	max = 0;
	while (stack)
	{
		data = (t_stack *)(stack->content);
		if (data->index > max)
			max = data->index;
		stack = stack->next;
	}
	return (max);
}

static int	ft_get_max_bits(t_list *stack)
{
	int	max;
	int	max_bits;

	max = ft_find_max_index(stack);
	max_bits = 0;
	while (max > 0)
	{
		max = max / 2;
		max_bits++;
	}
	return (max_bits);
}

static int	ft_get_bit(int index, int position)
{
	int	result;
	int	j;

	result = index;
	j = 0;
	while (j < position)
	{
		result = result / 2;
		j++;
	}
	return (result % 2);
}

void	ft_sort_radix(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;
	t_stack	*data;

	size = ft_lstsize(*stack_a);
	max_bits = ft_get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			data = (t_stack *)((*stack_a)->content);
			if (ft_get_bit(data->index, i) == 1)
				ft_rotate_stack_a(stack_a);
			else
				ft_push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			ft_push_a(stack_a, stack_b);
		i++;
	}
}
