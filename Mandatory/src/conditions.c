/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:10:44 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/17 17:14:04 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cond	*new_empty_condition(t_pile *a_pile, t_pile *b_pile, size_t maxsize)
{
	t_cond	*cond;

	cond = malloc(sizeof(t_cond));
	if (!cond)
		return (NULL);
	cond_pile_init(a_pile, b_pile, maxsize, cond);
	cond->dir = NULL;
	cond->last_dir = NULL;
	cond->next = NULL;
	return (cond);
}

t_cond	*new_condition_direction(t_cond **conds, t_cond *old_cond, char *line)
{
	t_cond	*cond;
	t_dir	*dir;

	cond = add_condition(conds, old_cond);
	if (!cond)
		return (NULL);
	dir = add_dir(&cond->dir, line);
	if (!dir)
	{
		free_condition(cond);
		return (NULL);
	}
	cond->last_dir = dir;
	execute_dirs(dir, cond->a_pile, cond->b_pile);
	return (cond);
}

void	free_condition(t_cond *conds)
{
	t_cond	*tmp;
	t_cond	*next;

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

t_cond	*init_condition(t_cond *new, t_cond *cond_from)
{
	new->a_pile = NULL;
	new->b_pile = NULL;
	new->dir = NULL;
	new->last_dir = NULL;
	new->next = NULL;
	new->a_pile = pile_copy(cond_from->a_pile);
	new->b_pile = pile_copy(cond_from->b_pile);
	new->dir = copy_dir(cond_from->dir);
	if (!new->a_pile || !new->b_pile || (cond_from->dir \
	&& !new->dir))
	{
		free_condition(new);
		return (NULL);
	}
	return (new);
}

t_cond	*add_condition(t_cond **conds, t_cond *cond_from)
{
	t_cond	*tmp;
	t_cond	*new;

	new = malloc(sizeof(t_cond));
	if (!new)
		return (NULL);
	new = init_condition(new, cond_from);
	tmp = *conds;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*conds = new;
	return (new);
}
