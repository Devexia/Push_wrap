#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	t_struc	struc;

	stack_a = parsing(ac, av, &struc);
	stack_b = ft_calloc(sizeof(int), struc.nb_of_nb + 1);
	if (!stack_b)
	{
		free(stack_a);
		exit(-1);
	}
	if (is_sorted(stack_a, &struc) == 0)
		what_algo(stack_a, stack_b, &struc);
	free(stack_a);
	free(stack_b);
	return (0);
}
