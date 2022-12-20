#include "push_swap.h"

size_t			count_dir(t_dir *dir)
{
	size_t nb;

	nb = 0;
	while (dir)
	{
		nb++;
		dir = dir->next;
	}
	return (nb);
}

int				pick_solution(t_init *init, t_cond *conds)
{
	t_cond			*solution;
	t_cond			*tmp_cond;

	solution = NULL;
	tmp_cond = conds->next;
	while (tmp_cond)
	{
		if (!solution || count_dir(tmp_cond->dir) <
count_dir(solution->dir))
			solution = tmp_cond;
		tmp_cond = tmp_cond->next;
	}
	if (!solution)
		solution = conds;
	if (solution->dir)
	{
		execute_dirs(solution->dir, &init->a_pile, &init->b_pile);
		if (!(init->dir = copy_dir(solution->dir)))
		{
			free_condition(conds);
			return (1);
		}
	}
	return (0);
}

int				realign_and_sort_a(t_init *init)
{
	t_dir	*tmp;

	if (init->b_pile.tab_size > 1 && align_b_pile(init))
		return (1);
	while (init->b_pile.tab_size)
	{
		if (init->b_pile.tab[0] > init->a_pile.tab[init->a_pile.tab_size - 1] ||
(init->b_pile.tab[0] < init->a_pile.tab[0] &&
init->a_pile.tab[0] < init->a_pile.tab[init->a_pile.tab_size - 1]))
			tmp = add_dir(&init->dir, "pa");
		else
			tmp = add_dir(&init->dir, "rra");
		if (!tmp)
			return (1);
		execute_dirs(tmp, &init->a_pile, &init->b_pile);
	}
	if (align_a_pile(init))
		return (1);
	return (0);
}

int				resolve(t_init *init)
{
	t_cond			*conds;

	if (!(conds = new_empty_condition(&init->a_pile, &init->b_pile,
init->a_pile.max_tab_size)))
		return (1);
	if (init->a_pile.tab_size > 5 &&
(create_condition_resolution(&conds) || large_resolve(conds)))
		return (1);
	if (pick_solution(init, conds))
		return (1);
	free_condition(conds);
	if (bruteforce_order_a(init))
		return (1);
	if (realign_and_sort_a(init))
		return (1);
	return (0);
}

void	print_direction(t_dir *dir)
{
	write(STDOUT_FILENO, dir->line, ft_strlen(dir->line));
	write(STDOUT_FILENO, "\n", 1);
}

void	print_directions(t_dir *dir)
{
	while(dir)
	{
		print_direction(dir);
		dir = dir->next;
	}
}
