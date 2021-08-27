#include "../push_swap.h"

void	three_ints(int *stack_a, t_struc *struc)
{
	if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2])
	{
		s(stack_a, "sa\n");
		R(stack_a, struc, "ra\n");
	}
	else if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2])
	{
		if (stack_a[1] - stack_a[2] < 0)
			R(stack_a, struc, "ra\n");
		else
		{
			s(stack_a, "sa\n");
			Reverse_r(stack_a, struc, "rra\n");
		}
	}
	else
	{
		if (stack_a[1] < stack_a[2])
			s(stack_a, "sa\n");
		else
			Reverse_r(stack_a, struc, "rra\n");
	}
}

void	four_ints(int *stack_a, int *stack_b, t_struc *struc)
{
	if (stack_a[3] == 1)
		Reverse_r(stack_a, struc, "rra\n");
	else
		while (stack_a[0] != 1)
			R(stack_a, struc, "ra\n");
	P(stack_a, stack_b, struc, "pb\n");
	if (is_sorted(stack_a, struc) == 0)
		three_ints(stack_a, struc);
	P(stack_b, stack_a, struc, "pa\n");
}

void	five_ints_p1(int *stack_a, int *stack_b, t_struc *struc)
{
	int	i;
	int	end;

	i = 0;
	end = 4;
	while (i < 2)
	{
		if (stack_a[end] == 1 || stack_a[end] == 5)
			Reverse_r(stack_a, struc, "rra\n");
		else if (stack_a[end - 1] == 1 || stack_a[end - 1] == 5)
		{
			Reverse_r(stack_a, struc, "rra\n");
			Reverse_r(stack_a, struc, "rra\n");
		}
		else
			while (stack_a[0] != 5 && stack_a[0] != 1)
				R(stack_a, struc, "ra\n");
		P(stack_a, stack_b, struc, "pb\n");
		end--;
		i++;
	}
}

void	five_ints_p2(int *stack_a, int *stack_b, t_struc *struc)
{
	if (is_sorted(stack_a, struc) == 0)
		three_ints(stack_a, struc);
	P(stack_b, stack_a, struc, "pa\n");
	if (stack_a[0] > stack_a[1])
		R(stack_a, struc, "ra\n");
	P(stack_b, stack_a, struc, "pa\n");
	if (stack_a[0] > stack_a[1])
		R(stack_a, struc, "ra\n");
}
