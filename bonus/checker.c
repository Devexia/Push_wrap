#include "../push_swap.h"
#include "../libft/libft.h"

int	do_commands2(char *line, int *stack_a, int *stack_b, t_struc *struc)
{
	if (!(ft_strncmp(line, "rb", 3)))
		R(stack_b, struc, NULL);
	else if (!(ft_strncmp(line, "rr", 3)))
		Rr(stack_a, stack_b, struc);
	else if (!(ft_strncmp(line, "exit\n", 4)) || !(ft_strncmp(line, "stop\n", 4)))
		return (0);
	else
		write(1, "commande non reconnue\n", 22);
	return (1);
}

int	do_commands(char *line, int *stack_a, int *stack_b, t_struc *struc)
{
	if (!(ft_strncmp(line, "sa", 3)))
		s(stack_a, NULL);
	else if (!(ft_strncmp(line, "sb", 3)))
		s(stack_b, NULL);
	else if (!(ft_strncmp(line, "ss", 3)))
		ss(stack_a, stack_b);
	else if (!(ft_strncmp(line, "pa", 3)))
		P(stack_b, stack_a, struc, NULL);
	else if (!(ft_strncmp(line, "pb", 3)))
		P(stack_a, stack_b, struc, NULL);
	else if (!(ft_strncmp(line, "rra", 4)))
		Reverse_r(stack_a, struc, NULL);
	else if (!(ft_strncmp(line, "rrb", 4)))
		Reverse_r(stack_b, struc, NULL);
	else if (!(ft_strncmp(line, "rrr", 4)))
		rrr(stack_a, stack_b, struc);
	else if (!(ft_strncmp(line, "ra", 3)))
		R(stack_a, struc, NULL);
	else if (do_commands2(line, stack_a, stack_b, struc) == 0)
		return (0);
	return (1);
}

void	end_checker(int *stack_a, int *stack_b, t_struc *struc)
{
	if (is_sorted(stack_a, struc) && stack_b[0] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
	free(stack_b);
}

int	main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	t_struc	struc;
	char	*line;

	stack_a = parsing(ac, av, &struc);
	stack_b = ft_calloc(sizeof(int), struc.nb_of_nb + 1);
	if (!stack_b)
	{
		free(stack_a);
		exit(-1);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (!(do_commands(line, stack_a, stack_b, &struc)))
			break ;
		free(line);
	}
	end_checker(stack_a, stack_b, &struc);
	free(line);
	return (0);
}
