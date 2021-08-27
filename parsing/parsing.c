#include "../push_swap.h"

int	av_len_boucle(int nb_of_nb, char **nb)
{
	int	c;
	int	i;

	i = -1;
	while (nb[++i])
	{
		c = 0;
		if (nb[i][c] == '-' && nb[i][c + 1] && '0' <= nb[i][c + 1] \
				&& nb[i][c + 1] <= '9')
			c++;
		if ('0' <= nb[i][c] && nb[i][c] <= '9')
		{
			while (nb[i][c] && '0' <= nb[i][c] && nb[i][c] <= '9')
				c++;
			nb_of_nb++;
		}
		if (nb[i][c] && !('0' <= nb[i][c] && nb[i][c] <= '9'))
		{
			write(1, "Error : character ", 19);
			write(1, &nb[i][c], 1);
			write(1, " not allowed\n", 13);
			exit(-1);
		}
	}
	return (nb_of_nb);
}

int	av_len_and_check(char **av, int ac)
{
	int		index_av;
	int		i;
	int		nb_of_nb;
	char	**nb;

	i = 0;
	nb_of_nb = 0;
	index_av = 0;
	while (++index_av < ac)
	{
		nb = ft_split(av[index_av], ' ');
		if (!nb)
			exit (-1);
		nb_of_nb = av_len_boucle(nb_of_nb, nb);
		ft_free_split(nb);
	}
	return (nb_of_nb);
}

void	av_to_tab2(int ac, char **av, int *stack_a)
{
	int		i_stack;
	char	**nb;
	int		index_av;
	int		i;

	i_stack = 0;
	index_av = 0;
	while (++index_av < ac)
	{
		nb = ft_split(av[index_av], ' ');
		if (!nb)
			exit (-1);
		i = -1;
		while (nb[++i])
		{
			if (('0' <= nb[i][0] && nb[i][0] <= '9') || nb[i][0] == '-')
			{
				stack_a[i_stack] = exist_and_min_max(nb, stack_a, i, i_stack);
				i_stack++;
			}
		}
		ft_free_split(nb);
	}
}

int	*av_to_tabint(int ac, char **av, t_struc *struc)
{
	int	*stack_a;

	struc->nb_of_nb = av_len_and_check(av, ac);
	stack_a = malloc(sizeof(int) * struc->nb_of_nb);
	if (!stack_a)
		exit(-1);
	av_to_tab2(ac, av, stack_a);
	return (stack_a);
}

//fct_1 verifie erreur de caractere et retourne
//le nombre de nombre qu'il y as pour malloc
//
//puis on split sur tout les av pour retirer les espaces
//et sur tout les split on met les int present
//dans tableau de int stack_a

int	*parsing(int ac, char **av, t_struc *struc)
{
	int	*stack_a_int;

	if (ac < 2)
		exit (-1);
	stack_a_int = av_to_tabint(ac, av, struc);
	if (!stack_a_int)
		exit(-1);
	stack_a_int = rank_stack(stack_a_int, struc);
	if (!stack_a_int)
		exit(-1);
	return (stack_a_int);
}
// met tout les argv dans un tab *int
//  puis change leurs valeurs par un rang
//  met ce tab *int dans une liste chaine pour pouvoir mieu manipule
