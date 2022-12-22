#include "/home/akhellad/Documents/push_swap/includes/push_swap.h"

void			calcul_sort_a(size_t *pos, size_t *mvt, t_pile *a_pile, t_pile *b_pile)
{
	*pos = 0;
	*mvt = 0;
	if (check_if_ordered(a_pile, ASC))
	{
		while (*pos < a_pile->tab_size - 1 &&
                a_pile->tab[*pos] < a_pile->tab[*pos + 1])
			(*pos)++;
		if (*pos > b_pile->tab_size / 2)
			*mvt = a_pile->tab_size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

void			calcul_sort_b(size_t *pos, size_t *mvt, t_pile *b_pile)
{
	*pos = 0;
	*mvt = 0;
	if (check_if_ordered(b_pile, DESC))
	{
		while (*pos < b_pile->tab_size - 1 &&
b_pile->tab[*pos] > b_pile->tab[*pos + 1])
			(*pos)++;
		if (*pos > b_pile->tab_size / 2)
			*mvt = b_pile->tab_size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

int				align_a_pile(t_init *init)
{
	size_t			i;
	size_t			num;
	t_dir	*tmp;

	calcul_sort_a(&i, &num, &init->a_pile, &init->b_pile);
	while (num--)
	{
		if (i > init->b_pile.tab_size / 2)
			tmp = add_dir(&init->dir, "rra");
		else
			tmp = add_dir(&init->dir, "ra");
		if (!tmp)
			return (1);
		execute_dirs(tmp, &init->a_pile, &init->b_pile);
	}
	return (0);
}

int			align_b_pile(t_init *init)
{
	size_t			i;
	size_t			num;
	t_dir	*tmp;

	calcul_sort_b(&i, &num, &init->b_pile);
	while (num--)
	{
		if (i > init->b_pile.tab_size / 2)
			tmp = add_dir(&init->dir, "rrb");
		else
			tmp = add_dir(&init->dir, "rb");
		if (!tmp)
			return (1);
		execute_dirs(tmp, &init->a_pile, &init->b_pile);
	}
	return (0);
}