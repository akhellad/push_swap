/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:07:32 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/17 16:07:47 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_direction(t_dir *dir)
{
	t_dir	*next;

	while (dir)
	{
		next = dir->next;
		free(dir->line);
		free(dir);
		dir = next;
	}
}

void	free_pile(t_pile *pile)
{
	free(pile->tab);
	free(pile);
}

void	free_init(t_init *init)
{
	free_direction(init->dir);
	free(init->a_pile.tab);
	free(init->b_pile.tab);
}
