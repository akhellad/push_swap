#include "./includes/push_swap.h"

int				reverse_rotate_bruteforce_a(t_cond **new_conds, t_cond *tmp, size_t pos[2], t_pile *p_pile)
{
	size_t			j;
	t_dir	*tmp_dir;

	tmp_dir = tmp->last_dir;
	j = 0;
	while (j++ < tmp->a_pile->tab_size / 2 && tmp_dir &&
(!ft_strcmp(tmp_dir->line, "rra") || !ft_strcmp(tmp_dir->line, "rrr")))
		tmp_dir = tmp->last_dir->prev;
	if (!tmp->last_dir || ((ft_strcmp(tmp->last_dir->line, "ra") &&
ft_strcmp(tmp->last_dir->line, "rr") && j < tmp->a_pile->tab_size / 2)))
	{
		if (pos[0] > p_pile->tab_size / 2 && !tmp->b_pile->tab_size && pos[1])
		{
			pos[1]--;
			if (!new_condition_direction(new_conds, tmp, "rrr"))
				return (1);
		}
		else if (!new_condition_direction(new_conds, tmp, "rra"))
			return (1);
	}
	return (0);
}

int				rotate_bruteforce_a(t_cond **new_conds, t_cond *tmp, size_t pos[2], t_pile *b_pile)
{
	size_t			j;
	t_dir	*tmp_dir;

	tmp_dir = tmp->last_dir;
	j = 0;
	while (j++ < tmp->a_pile->tab_size / 2 && tmp_dir &&
(!ft_strcmp(tmp_dir->line, "ra") || !ft_strcmp(tmp_dir->line, "rr")))
		tmp_dir = tmp->last_dir->prev;
	if (!tmp->last_dir || ((ft_strcmp(tmp->last_dir->line, "rra") &&
ft_strcmp(tmp->last_dir->line, "rrr") && j < tmp->a_pile->tab_size / 2)))
	{
		if (pos[0] <= b_pile->tab_size / 2 && !tmp->b_pile->tab_size && pos[1])
		{
			pos[1]--;
			if (!new_condition_direction(new_conds, tmp, "rr"))
				return (1);
		}
		else if (!new_condition_direction(new_conds, tmp, "ra"))
			return (1);
	}
	return (0);
}

int				bruteforce_choice_a(t_cond **new_conds, t_cond *tmp, size_t pos[2], t_pile *b_pile)
{
	if (tmp->b_pile->tab_size < 2 && (!tmp->last_dir ||
ft_strcmp(tmp->last_dir->line, "pa")) &&
!new_condition_direction(new_conds, tmp, "pb"))
		return (1);
	if (tmp->b_pile->tab_size > 0 && (!tmp->last_dir ||
ft_strcmp(tmp->last_dir->line, "pb")) &&
!new_condition_direction(new_conds, tmp, "pa"))
		return (1);
	if (!tmp->last_dir || (ft_strcmp(tmp->last_dir->line, "sa") &&
ft_strcmp(tmp->last_dir->line, "sb") &&
ft_strcmp(tmp->last_dir->line, "ss")))
	{
		if (!new_condition_direction(new_conds, tmp, "sa"))
			return (1);
		if (tmp->b_pile->tab_size > 1 &&
!new_condition_direction(new_conds, tmp, "sb"))
			return (1);
		if (tmp->b_pile->tab_size > 1 &&
!new_condition_direction(new_conds, tmp, "ss"))
			return (1);
	}
	if (rotate_bruteforce_a(new_conds, tmp, pos, b_pile))
		return (1);
	return (reverse_rotate_bruteforce_a(new_conds, tmp, pos, b_pile));
}