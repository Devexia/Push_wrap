#include "../push_swap.h"

void	P(int *stack_a, int *stack_b, t_struc *struc, char *affichage)
{
	int	tmp;
	int	i;
	int	j;

	if (stack_a[0] == 0)
		return ;
	i = 0;
	j = 1;
	tmp = stack_a[0];
	while (j < struc->nb_of_nb && stack_a[j] != 0)
	{
		stack_a[i] = stack_a[j];
		i++;
		j++;
	}
	stack_a[i] = 0;
	i = struc->nb_of_nb - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = tmp;
	write(1, affichage, 3);
}
