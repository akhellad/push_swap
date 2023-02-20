/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:08:10 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/17 18:33:49 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	execute_dirs(t_dir *instr, t_pile *stack_a, t_pile *stack_b)
{
	while (instr)
	{
		if (!ft_strcmp(instr->line, "sa") || !ft_strcmp(instr->line, "ss"))
			st(stack_a);
		if (!ft_strcmp(instr->line, "sb") || !ft_strcmp(instr->line, "ss"))
			st(stack_b);
		if (!ft_strcmp(instr->line, "pa"))
			pt(stack_a, stack_b);
		if (!ft_strcmp(instr->line, "pb"))
			pt(stack_b, stack_a);
		if (!ft_strcmp(instr->line, "ra") || !ft_strcmp(instr->line, "rr"))
			rt(stack_a);
		if (!ft_strcmp(instr->line, "rb") || !ft_strcmp(instr->line, "rr"))
			rt(stack_b);
		if (!ft_strcmp(instr->line, "rra") || !ft_strcmp(instr->line, "rrr"))
			rrt(stack_a);
		if (!ft_strcmp(instr->line, "rrb") || !ft_strcmp(instr->line, "rrr"))
			rrt(stack_b);
		instr = instr->next;
	}
}

t_dir	*add_dir(t_dir **dirs, char *line)
{
	t_dir	*tmp;
	t_dir	*new;

	new = malloc(sizeof(t_dir));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	if (!new->line)
	{
		free(new);
		return (NULL);
	}
	new->prev = NULL;
	new->next = NULL;
	tmp = *dirs;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		new->prev = tmp;
		tmp->next = new;
	}
	else
		*dirs = new;
	return (new);
}

t_dir	*copy_dir(t_dir *dir)
{
	t_dir	*new;

	new = NULL;
	while (dir)
	{
		if (!(add_dir(&new, dir->line)))
		{
			free_direction(new);
			return (NULL);
		}
		dir = dir->next;
	}
	return (new);
}

