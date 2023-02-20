/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:08:10 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/17 16:10:03 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_dir	*add_n_dirs(t_dir **dir, char *line, size_t n)
{
	t_dir	*start;

	start = NULL;
	if (n > 0)
	{
		start = add_dir(dir, line);
		if (!start)
			return (NULL);
		n--;
		while (n > 0)
		{
			if (!(add_dir(dir, line)))
			{
				free_direction(start);
				return (NULL);
			}
			n--;
		}
	}
	return (start);
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

t_dir	*copy_and_concat_dir(t_dir **instr, t_dir *new)
{
	t_dir	*ptr;
	t_dir	*tmp_instr;

	tmp_instr = *instr;
	if (tmp_instr)
	{
		while (tmp_instr->next)
			tmp_instr = tmp_instr->next;
		tmp_instr->next = copy_dir(new);
		if (!tmp_instr->next)
			return (NULL);
		ptr = tmp_instr->next;
		((t_dir *)tmp_instr->next)->prev = tmp_instr;
	}
	else
	{
		*instr = copy_dir(new);
		ptr = *instr;
	}
	return (ptr);
}
