#include "push_swap.h"

int	ft_count_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int ft_check_double(char **argv)
{
    int i;
    int j;
    int length;

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

int ft_check_nb(char *argv)
{
    int i;

    i = 0;
    if (argv[i] == '-')
        i++;
    while (argv[i])
    {
        if (!ft_isdigit(argv[i]))
            return (1);
        i++;
    }
    return (0);
}

void ft_check_input(int argc, char **argv)
{
    int i;
    long    tmp_argv;
    char    **buffer;

    i = 0;
    if (argc == 2)
        buffer = ft_split(argv[1], ' ');
    else
        buffer = argv + 1;
    while (buffer[i])
    {
        tmp_argv = ft_atoi(buffer[i]);
        if (tmp_argv < INT_MIN || tmp_argv > INT_MAX)
            ft_error();
        if (ft_check_nb(buffer[i]))
            ft_error();
        if (ft_check_double(buffer))
            ft_error();
        i++;
    }
    if (argc == 2)
        ft_free(buffer);
}