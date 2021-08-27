#include "../push_swap.h"

void	switch_value(int *ranked_stack_i, int rang, int *searcher, int stack_a)
{
	(*ranked_stack_i) = rang;
	(*searcher) = stack_a;
}

int	*rank_stack_2(int tab[], t_struc *struc, int *stack_a)
{
	int	*ranked_stack;
	int	rang;
	int	i;
	int	searcher;

	rang = 1;
	ranked_stack = ft_calloc(sizeof(int), struc->nb_of_nb);
	if (!ranked_stack)
		return (NULL);
	while (++rang < struc->nb_of_nb)
	{
		i = -1;
		searcher = tab[max];
		while (++i < struc->nb_of_nb)
		{
			if (stack_a[i] < searcher && stack_a[i] > tab[min])
				switch_value(&ranked_stack[i], rang, &searcher, stack_a[i]);
		}
		tab[min] = searcher;
	}
	ranked_stack[tab[2]] = 1;
	ranked_stack[tab[3]] = struc->nb_of_nb;
	free(stack_a);
	return (ranked_stack);
}

int	*rank_stack(int *stack_a, t_struc *struc)
{
	int	i;
	int	tab[4];

	i = -1;
	tab[min] = stack_a[0];
	tab[max] = stack_a[0];
	tab[2] = 0;
	tab[3] = 0;
	while (++i < struc->nb_of_nb)
	{
		if (stack_a[i] <= tab[min])
		{
			tab[min] = stack_a[i];
			tab[2] = i;
		}
		if (stack_a[i] >= tab[max])
		{
			tab[max] = stack_a[i];
			tab[3] = i;
		}
	}
	return (rank_stack_2(tab, struc, stack_a));
}
