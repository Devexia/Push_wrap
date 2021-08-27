#include "../push_swap.h"

t_existance	verif_exist_nb(int nb, int nb_of_nb, int *stack)
{
	int	i;

	i = -1;
	while (++i < nb_of_nb)
	{
		if (stack[i] == nb)
			return (already_exist);
	}
	return (dont_exist);
}

void	check_limit(long nb)
{
	if (nb > INT_MAX)
	{
		ft_putstr_fd("Error : value greater than int max\n", 1);
		exit (-1);
	}
	if (nb < INT_MIN)
	{
		ft_putstr_fd("Error : value less than int min\n", 1);
		exit (-1);
	}
}

int	exist_and_min_max(char **av, int *stack_a, int i, int i_stack)
{
	long	nb;
	int		j;

	nb = 0;
	j = 0;
	if (av[i][j] == '-')
		j++;
	while (av[i][j] && '0' <= av[i][j] && av[i][j] <= '9')
	{
		nb = nb * 10 + av[i][j] - '0';
		j++;
	}
	if (av[i][0] == '-')
		nb = nb * -1;
	check_limit(nb);
	if (verif_exist_nb(nb, i_stack, stack_a) == already_exist)
	{
		ft_putstr_fd("Error : duplicates of ", 1);
		ft_putnbr_fd(nb, 1);
		write(1, "\n", 1);
		free(stack_a);
		exit(-1);
	}
	return ((int)nb);
}
