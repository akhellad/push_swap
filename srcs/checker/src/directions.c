/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:08:10 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/21 17:18:32 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	execute_dirs(t_dir *instr, t_pile *stack_a, t_pile *stack_b)
{
	while (instr)
	{
		if (!ft_strcmp(instr->line, "sa\n") || !ft_strcmp(instr->line, "ss\n"))
			st(stack_a);
		if (!ft_strcmp(instr->line, "sb\n") || !ft_strcmp(instr->line, "ss"))
			st(stack_b);
		if (!ft_strcmp(instr->line, "pa\n"))
			pt(stack_a, stack_b);
		if (!ft_strcmp(instr->line, "pb\n"))
			pt(stack_b, stack_a);
		if (!ft_strcmp(instr->line, "ra\n") || !ft_strcmp(instr->line, "rr\n"))
			rt(stack_a);
		if (!ft_strcmp(instr->line, "rb\n") || !ft_strcmp(instr->line, "rr\n"))
			rt(stack_b);
		if (!ft_strcmp(instr->line, "rra\n") || !ft_strcmp(instr->line, "rrr\n"))
			rrt(stack_a);
		if (!ft_strcmp(instr->line, "rrb\n") || !ft_strcmp(instr->line, "rrr\n"))
			rrt(stack_b);
		instr = instr->next;
	}
}


int		add_dir(t_dir **dirs, char *line)
{
	t_dir *tmp;
	t_dir *new;

	if (!(new = malloc(sizeof(t_dir))))
		return (1);
	new->line = ft_strdup(line);
	new->next = NULL;
	tmp = *dirs;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*dirs = new;
	return (0);
}

