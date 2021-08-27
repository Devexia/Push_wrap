#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stdio.h"
# include "string.h"
# include "errno.h"
# include "structure.h"
# include "limits.h"

//parsing
int			*rank_stack(int *stack_a, t_struc *struc);
int			*parsing(int ac, char **av, t_struc *struc);
int			last_number(int *stack, t_struc *struc);
int			exist_and_min_max(char **av, int *stack_a, int i, int i_stack);
t_existance	verif_exist_nb(int nb, int nb_of_nb, int *stack);
//============================//
//instruction
void		Reverse_r(int *stack, t_struc *struc, char *affichage);
void		R(int *stack, t_struc *struc, char *affichage);
void		ss(int *stack_a, int *stack_b);
void		s(int *stack, char *affichage);
void		P(int *stack_a, int *stack_b, t_struc *struc, char *affichage);
void		Rr(int *stack_a, int *stack_b, t_struc *struc);
void		rrr(int *stack_a, int *stack_b, t_struc *struc);
//============================//
//the different algo
void		what_algo(int *stack_a, int *stack_b, t_struc *struc);
void		three_ints(int *stack_a, t_struc *struc);
void		four_ints(int *stack_a, int *stack_b, t_struc *struc);
void		five_ints_p1(int *stack_a, int *stack_b, t_struc *struc);
void		five_ints_p2(int *stack_a, int *stack_b, t_struc *struc);
void		big_algo(int *stack_a, int *stack_b, t_struc *struc);
//===========================//
//fct aide algo
void		take_min(int *stack_a, int *stack_b, t_struc *struc);
void		take_max(int *stack_a, int *stack_b, t_struc *struc);
void		where_in_B(int *stack_a, int *stack_b, t_struc *struc);
int			is_sorted(int *stack_a, t_struc *struc);
//===========================//

#endif
