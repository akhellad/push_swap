#include "push_swap.h"

int check_double(t_pile *pile, int nbr)
{
    size_t i;

    i = 0;
    while(i < pile->tab_size)
    {
        if(pile->tab[i] == nbr)
            return (1);
        i ++;
    }
    return (0);
}

int     check_if_ordered(t_pile *pile, int order)
{
    size_t i;

	i = 0;
	while (i < pile->tab_size - 1)
	{
		if ((order == ASC && pile->tab[i] >= pile->tab[i + 1])
			|| (order == DESC && pile->tab[i] <= pile->tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

t_pile   *pile_copy(t_pile *pile)
{
    size_t  i;
    t_pile   *new_pile;

    if(!(new_pile = malloc(sizeof(t_pile))))
        return (NULL);
    if(!(pile->tab = malloc(sizeof(int) * pile->max_tab_size)))
        return (NULL);
    i = 0;
    while (i < pile->tab_size)
    {
        new_pile->tab[i] = pile->tab[i];
        i ++;
    }
    new_pile->tab_size = pile->tab_size;
    new_pile->max_tab_size = pile->max_tab_size;
    return (new_pile);
}

t_pile   *new_empty_pile(size_t max_size)
{
    t_pile   *pile;

    if(!(pile = malloc(sizeof(t_pile))))
        return (NULL);
    if(!(pile->tab = malloc(sizeof(int) * max_size)))
    {
        free(pile);
        return (NULL);
    }
    pile->max_tab_size = max_size;
    pile->tab_size = 0;
    return (pile);
}