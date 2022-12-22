#include "/home/akhellad/Documents/push_swap/includes/push_swap.h"

int					create_condition_resolution(t_cond **condition)
{
	int				i;
	t_dir	*tmp;
	t_cond			*new;

	i = -DEPTH - 1;
	while (++i < DEPTH)
	{
		tmp = NULL;
		if (!i)
			new = new_condition_direction(condition, *condition, "pb");
		else if (i < 0)
		{
			new = new_condition_direction(condition, *condition, "ra");
			tmp = add_n_dirs(&new->dir, "ra", DEPTH + i);
		}
		else if (i > 0)
		{
			new = new_condition_direction(condition, *condition, "rra");
			tmp = add_n_dirs(&new->dir, "rra", i - 1);
		}
		execute_dirs(tmp, new->a_pile, new->b_pile);
		if (!new || (!tmp && i && i != -DEPTH && i != 1))
			return (1);
	}
	return (0);
}

t_dir		*rotate_a(t_cond *stt, size_t min[2], size_t min_mvt[2])
{
	t_dir		*instr;

	if (min[0] <= min[1] && min_mvt[0] <= stt->b_pile->tab_size / 2)
		instr = add_dir(&stt->dir, "rr");
	else if (min[0] < min[1] && min_mvt[0] > stt->b_pile->tab_size / 2)
		instr = add_dir(&stt->dir, "ra");
	else if (min_mvt[1] > stt->b_pile->tab_size / 2)
		instr = add_dir(&stt->dir, "rrr");
	else
		instr = add_dir(&stt->dir, "rra");
	return (instr);
}

t_dir		*rotate(t_cond *stt)
{
	t_dir		*instr;
	size_t				mvt[2];
	size_t				min[2];
	size_t				min_mvt[2];

	mvt[0] = closer_pos_to_inf(stt->a_pile->tab[0], stt->b_pile);
	min[0] = less_mvt_at_begin(mvt[0], &min_mvt[0], stt->a_pile, stt->b_pile);
	min[1] = less_mvt_at_end(mvt[0], &min_mvt[1], stt->a_pile, stt->b_pile);
	if (mvt[0] > stt->b_pile->tab_size / 2)
		mvt[1] = stt->b_pile->tab_size - mvt[0];
	else
		mvt[1] = mvt[0];
	if (stt->a_pile->tab_size > 1 && (min[0] <= mvt[1] || min[1] <= mvt[1]))
		instr = rotate_a(stt, min, min_mvt);
	else if (mvt[0] > stt->b_pile->tab_size / 2)
		instr = add_dir(&stt->dir, "rrb");
	else
		instr = add_dir(&stt->dir, "rb");
	return (instr);
}

int					large_resolve(t_cond *conds)
{
	t_dir	*tmp;
	t_cond			*tmp_cond;

	tmp_cond = conds->next;
	while (tmp_cond)
	{
		while (tmp_cond->a_pile->tab_size > 5)
		{
			if (can_pb(tmp_cond->a_pile, tmp_cond->b_pile))
				tmp = add_dir(&tmp_cond->dir, "pb");
			else
				tmp = rotate(tmp_cond);
			if (!tmp)
			{
				free_condition(conds);
				return (1);
			}
			execute_dirs(tmp, tmp_cond->a_pile, tmp_cond->b_pile);
		}
		tmp_cond = tmp_cond->next;
	}
	return (0);
}