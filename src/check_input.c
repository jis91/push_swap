#include "push_swap.h"

int	ft_count_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	ft_check_double(char **argv)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = ft_count_arg(argv);
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_nb(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (1);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	ft_check_args(char **buffer)
{
	int		i;
	long	tmp;

	i = 0;
	while (buffer[i])
	{
		tmp = ft_atol(buffer[i]);
		if (tmp < INT_MIN || tmp > INT_MAX || ft_check_nb(buffer[i]))
			ft_error();
		i++;
	}
	if (ft_check_double(buffer))
		ft_error();
}

void	ft_check_input(int argc, char **argv)
{
	char	**buffer;

	if (argc == 2)
	{
		buffer = ft_split(argv[1], ' ');
		if (!buffer || !buffer[0])
			ft_error();
		ft_check_args(buffer);
		ft_free_tab(buffer);
	}
	else
		ft_check_args(argv + 1);
}
