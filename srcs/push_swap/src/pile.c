/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:43:07 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/21 16:50:30 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Regarde la pile a possède le nombre donné 
*/

int	check_double(t_pile *pile, int nbr)
{
	size_t	i;

	i = 0;
	while (i < pile->tab_size)
	{
		if (pile->tab[i] == nbr)
			return (1);
		i ++;
	}
	return (0);
}

/*
** Regarde si la pile a est triée dans l'ordre croissant ou decroissant
*/
#include <stdio.h>

int	check_if_ordered(t_pile *pile, int order)
{
	size_t	i;

	i = 0;
	while (i < pile->tab_size - 1)
	{
		if ((order == ASC && pile->tab[i] >= pile->tab[i + 1])
			|| (order == DESC && pile->tab[i] <= pile->tab[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

/*
** Copie une pile 
*/

t_pile	*pile_copy(t_pile *pile)
{
	size_t	i;
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->tab = malloc(sizeof(int) * pile->max_tab_size);
	if (!new->tab)
		return (NULL);
	i = 0;
	while (i < pile->tab_size)
	{
		new->tab[i] = pile->tab[i];
		i++;
	}
	new->tab_size = pile->tab_size;
	new->max_tab_size = pile->max_tab_size;
	return (new);
}

/*
** Crée une pile vide d'une taille donnée 
*/

t_pile	*new_empty_pile(size_t max_size)
{
	t_pile	*pile;

	pile = malloc(sizeof(t_pile));
	if (!pile)
		return (NULL);
	pile->tab = malloc(sizeof(int) * max_size);
	if (!pile->tab)
	{
		free(pile);
		return (NULL);
	}
	pile->max_tab_size = max_size;
	pile->tab_size = 0;
	return (pile);
}
