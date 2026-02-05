#include "push_swap.h"

static t_list	*ft_create_node(char *str, t_list *stack)
{
	t_stack	*data;
	t_list	*new;

	data = malloc(sizeof(t_stack));
	if (!data)
	{
		ft_free_stack(&stack);
		ft_error();
	}
	data->nbr = ft_atoi(str);
	data->index = -1;
	new = ft_lstnew(data);
	if (!new)
	{
		free(data);
		ft_free_stack(&stack);
		ft_error();
	}
	return (new);
}

static t_list	*ft_init_from_string(char *str)
{
	char	**tmp;
	t_list	*stack;
	int		i;

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

static t_list	*ft_init_from_args(char **argv)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (argv[i])
	{
		ft_lstadd_back(&stack, ft_create_node(argv[i], stack));
		i++;
	}
	return (stack);
}

t_list	*ft_init_stack_a(int argc, char **argv)
{
	if (argc == 2)
		return (ft_init_from_string(argv[1]));
	else
		return (ft_init_from_args(argv + 1));
}
