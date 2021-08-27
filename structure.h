#ifndef  STRUCTURE_H
# define STRUCTURE_H

# include "libft/libft.h"

typedef struct s_struc {
	int	nb_of_nb;
	int	min;
	int	max;

}	t_struc;

typedef enum e_tab {
	min = 0,
	max = 1,
}			t_tab;

typedef enum e_existance {
	already_exist,
	dont_exist,
}			t_existance;

#endif
