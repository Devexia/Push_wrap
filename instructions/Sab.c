#include "../push_swap.h"

void	s(int *stack, char *affichage)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	write(1, affichage, 3);
}

void	ss(int *stack_a, int *stack_b)
{
	s(stack_a, "");
	s(stack_b, "");
	write(1, "ss\n", 3);
}
