#include "../push_swap.h"

void	R(int *stack, t_struc *struc, char *affichage)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	while (stack[i] != 0 && i < struc->nb_of_nb)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i - 1] = tmp;
	write(1, affichage, 3);
}

void	Reverse_r(int *stack, t_struc *struc, char *affichage)
{
	int	tmp;
	int	i;

	i = struc->nb_of_nb - 1;
	while (stack[i] == 0)
		i--;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
	write(1, affichage, 4);
}

void	rrr(int *stack_a, int *stack_b, t_struc *struc)
{
	Reverse_r(stack_a, struc, NULL);
	Reverse_r(stack_b, struc, NULL);
}

void	Rr(int *stack_a, int *stack_b, t_struc *struc)
{
	R(stack_a, struc, NULL);
	R(stack_b, struc, NULL);
}
