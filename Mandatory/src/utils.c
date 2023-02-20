/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:34:15 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/17 17:16:15 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	print_dirs(t_dir *dir)
{
	while (dir)
	{
		print_dir(dir);
		dir = dir->next;
	}
}

t_cond	*cond_pile_init(t_pile *a_pile, t_pile *b_pile, \
						size_t maxsize, t_cond *cond)
{
	if (a_pile)
		cond->a_pile = pile_copy(a_pile);
	else
		cond->a_pile = new_empty_pile(maxsize);
	if (!cond->a_pile)
	{
		free(cond);
		return (NULL);
	}
	if (b_pile)
		cond->b_pile = pile_copy(b_pile);
	else
		cond->b_pile = new_empty_pile(maxsize);
	if (!cond->b_pile)
	{
		free(cond->a_pile);
		free(cond);
		return (NULL);
	}
	return (cond);
}
