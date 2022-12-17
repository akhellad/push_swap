#include "push_swap.c"

t_cond   *new_empty_condition(t_pile *a_pile, t_pile *b_pile, size_t maxsize)
{
    t_cond   *cond;

    if (!(cond = malloc(sizeof(t_cond))))
        return (NULL);
    if(a_pile)
        cond->a_pile = pile_copy(a_pile);
    else if (!(cond->a_pile = new_empty_pile(maxsize)))
    {
        free(cond);
        return (NULL);
    }
    if(b_pile)
        cond->b_pile = pile_copy(b_pile);
    else if (!(cond->b_pile = new_empty_pile(maxsize)))
    {
        free(cond->a_pile);
        free(cond);
        return (NULL);
    }
    cond->dir = NULL;
    cond->last_dir = NULL;
    cond->next = NULL;
    return (cond);
}

t_cond			*new_condition_direction(t_cond **conds, t_cond *old_cond, char *line)
{
	t_cond			*cond;
	t_dir	*dir;

	if (!(cond = add_condition(conds, old_cond)))
		return (NULL);
	if (!(dir = add_dir(&cond->dir, line)))
	{
		free_condition(cond);
		return (NULL);
	}
	cond->last_dir = dir;
	execute_dirs(dir, cond->a_pile, cond->b_pile);
	return (cond);
}

void			free_condition(t_cond *conds)
{
	t_cond			*tmp;
	t_cond			*next;

	tmp = conds;
	while (tmp)
	{
		next = tmp->next;
		free_pile(tmp->a_pile);
		free_pile(tmp->b_pile);
		free_direction(tmp->dir);
		free(tmp);
		tmp = next;
	}
}

t_cond			*add_condition(t_cond **conds, t_cond *cond_from)
{
	t_cond		*tmp;
	t_cond		*new;

	if (!(new = malloc(sizeof(t_cond))))
		return (NULL);
	new->a_pile = NULL;
	new->b_pile = NULL;
	new->dir = NULL;
	new->last_dir = NULL;
	new->next = NULL;
	if (!(new->a_pile = pile_copy(cond_from->a_pile)) ||
!(new->b_pile = pile_copy(cond_from->b_pile)) || (cond_from->dir
	&& !(new->dir = copy_dir(cond_from->dir))))
	{
		free_condition(new);
		return (NULL);
	}
	tmp = *conds;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*conds = new;
	return (new);
}