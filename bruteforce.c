#include "push_swap.h"

int		check_bruteforce_solution(t_cond *conds, t_cond **result)
{
	while (conds && !(*result))
	{
		if (!conds->b_pile->tab_size && !check_if_ordered(conds->a_pile, ASC))
		{
			if (!add_condition(result, conds))
			{
				free_condition(conds);
				return (1);
			}
		}
		conds = conds->next;
	}
	return (0);
}

t_cond			*pick_bruteforce_solution(t_cond *conds, size_t pos[2], t_pile *b_pile)
{
	t_cond			*result;
	t_cond			*new_conds;
	t_cond			*tmp;

	result = NULL;
	while (!result)
	{
		new_conds = NULL;
		tmp = conds;
		while (tmp)
		{
			if (bruteforce_choice_a(&new_conds, tmp, pos, b_pile))
			{
				free_condition(new_conds);
				return (NULL);
			}
			tmp = tmp->next;
		}
		free_condition(conds);
		conds = new_conds;
		if (check_bruteforce_solution(conds, &result))
			return (NULL);
	}
	free_condition(conds);
	return (result);
}

int				bruteforce_order_a(t_init *init)
{
	size_t			pos[2];
	t_cond			*result;
	t_cond			*conds;

	calcul_sort_b(&pos[0], &pos[1], &init->b_pile);
	if (!(conds = new_empty_condition(&init->a_pile, NULL, init->a_pile.max_tab_size)))
		return (1);
	if (!(result = pick_bruteforce_solution(conds, pos, &init->b_pile)))
	{
		free_condition(conds);
		return (1);
	}
	execute_dirs(result->dir, &init->a_pile, &init->b_pile);
	if (!copy_and_concat_dir(&init->dir, result->dir))
	{
		free_condition(result);
		return (1);
	}
	free_condition(result);
	return (0);
}