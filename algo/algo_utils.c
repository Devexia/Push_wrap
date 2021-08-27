#include "../push_swap.h"

void	two_nums(int *stack_a)
{
	if (stack_a[0] == 2)
		s(stack_a, "sa\n");
}

void	what_algo(int *stack_a, int *stack_b, t_struc *struc)
{
	if (struc->nb_of_nb == 2)
		two_nums(stack_a);
	else if (struc->nb_of_nb == 3)
		three_ints(stack_a, struc);
	else if (struc->nb_of_nb == 4)
		four_ints(stack_a, stack_b, struc);
	else if (struc->nb_of_nb == 5)
	{
		five_ints_p1(stack_a, stack_b, struc);
		five_ints_p2(stack_a, stack_b, struc);
	}
	else
		big_algo(stack_a, stack_b, struc);
}

int	last_number(int *stack, t_struc *struc)
{
	int	i;

	i = struc->nb_of_nb - 1;
	while (stack[i] == 0 && i > 0)
		i--;
	return (i);
}

int	is_sorted(int *stack_a, t_struc *struc)
{
	int	i;

	i = 1;
	while (i < struc->nb_of_nb && stack_a[i - 1] < stack_a[i])
		i++;
	if (i == struc->nb_of_nb || stack_a[i] == 0)
		return (1);
	return (0);
}
