#include "../push_swap.h"

int	ft_get_to_the_top(int *stack, int i, int j, t_struc *struc)
{
	if (j == last_number(stack, struc))
		j = 0;
	else
		j = last_number(stack, struc) - j;
	if (j < 0 && i <= 0)
		return (0);
	if (i < j)
		while (i-- > 0)
			R(stack, struc, "ra\n");
	else
	{
		while (j-- >= 0)
			Reverse_r(stack, struc, "rra\n");
	}
	return (1);
}

void	get_num_to_push(int *stack, t_struc *struc, int chunk)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i] != 0 && stack[i] > chunk)
		i++;
	j = last_number(stack, struc);
	while (stack[j] > chunk)
		j--;
	if (i != 0)
		ft_get_to_the_top(stack, i, j, struc);
}

void	where_in_B(int *stack_a, int *stack_b, t_struc *struc)
{
	P(stack_a, stack_b, struc, "pb\n");
	if (stack_b[1] == 0 || stack_b[0] > stack_b[1])
		return ;
	if (stack_b[0] < stack_b[last_number(stack_b, struc)])
		R(stack_b, struc, "rb\n");
	else
		s(stack_b, "sb\n");
}

void	Push_all_in_a(int *stack_a, int *stack_b, t_struc *struc)
{
	int	i;
	int	num_to_push;
	int	j;

	num_to_push = struc->nb_of_nb;
	while (stack_b[0] != 0)
	{
		i = 0;
		while (stack_b[i] != num_to_push)
			i++;
		if (i > last_number(stack_b, struc) / 2)
		{
			j = last_number(stack_b, struc) - i;
			while (j-- >= 0)
				Reverse_r(stack_b, struc, "rrb\n");
		}
		else
			while (i-- > 0)
				R(stack_b, struc, "rb\n");
		num_to_push--;
		P(stack_b, stack_a, struc, "pa\n");
	}
}

void	big_algo(int *stack_a, int *stack_b, t_struc *struc)
{
	int	i;
	int	j;
	int	chunk;
	int	chunk_count;

	i = 0;
	while (i * i <= struc->nb_of_nb)
		i++;
	chunk_count = i / 2;
	chunk = struc->nb_of_nb / chunk_count;
	i = 0;
	while (i <= chunk_count)
	{
		j = 0;
		while (j < struc->nb_of_nb / chunk_count && stack_a[0] != 0)
		{
			get_num_to_push(stack_a, struc, chunk);
			where_in_B(stack_a, stack_b, struc);
			j++;
		}
		chunk += (struc->nb_of_nb / chunk_count);
		i++;
	}
	Push_all_in_a(stack_a, stack_b, struc);
}
