#include "push_swap.h"

void    rrt(t_pile *pile)
{
    size_t i;
    int tmp;

    if(pile->tab_size > 1)
    {
        tmp = pile->tab[pile->tab_size - 1];
        i = pile->tab_size - 1;
        while(i > 0)
        {
            pile->tab[i] = pile->tab[i - 1];
            i --;
        }
        pile->tab[0] = tmp;
    }
}

void	rt(t_pile *pile)
{
	size_t	i;
	int		tmp;

	if (pile->tab_size > 1)
	{
		tmp = pile->tab[0];
		i = 0;
		while (i < pile->tab_size - 1)
		{
			pile->tab[i] = pile->tab[i + 1];
			i++;
		}
		pile->tab[pile->tab_size - 1] = tmp;
	}
}

void			pt(t_pile *pile1, t_pile *pile2)
{
	if (pile2->tab_size > 0)
	{
		pile1->tab_size++;
		rrt(pile1);
		pile1->tab[0] = pile2->tab[0];
		rt(pile2);
		pile2->tab_size--;
	}
}

void			st(t_pile *pile)
{
	int tmp;

	if (pile->tab_size > 1)
	{
		tmp = pile->tab[0];
		pile->tab[0] = pile->tab[1];
		pile->tab[1] = tmp;
	}
}