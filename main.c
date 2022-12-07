#include "push_swap.h"

int	check_if_sorted(int *t, int top)
{
	int	i;
	int	j;

	i = 0;
	while (i < top)
	{
		j = i + 1;
		while (j <= top)
		{
			if (t[i] < t[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	sort_3nb(t_tab *var, int c)
{
	if (c == 3)
	{
		if (check_if_sorted(var->a_pile, var->a_top) != 0)
			sa(var->a_pile, var->a_top, '1');
		return ;
	}
	while (check_if_sorted(var->a_pile, var->a_top) != 0)
	{
		if (var->a_pile[var->a_top] > var->a_pile[(var->a_top) - 1])
		{
			sa(var->a_pile, var->a_top, '1');
			if (check_if_sorted(var->a_pile, var->a_top) != 0)
				rra(var->a_pile, var->a_top, '1');
		}
		else
			rra(var->a_pile, var->a_top, '1');
	}
}

int main(int ac, char **av)
{
    char **tmp;
    int count;
    t_tab pile;
    int i = 0;
    tmp = parc(ac, av, tmp);
    count = count_digit(tmp);
    if(check_digit(count, tmp) == 1)
    {
        ft_printf("Error\n");
        return (0);
    }
    if(check_doubl(tmp, count) == 1)
    {
        ft_printf("Error\n");
        return (0);
    }
    pile.a_pile = char_to_int(tmp, count, &pile);
    if (check_if_sorted(pile.a_pile, count) == 0)
    {
        ft_printf("\n");
        return (0);
    }
    while(pile.a_pile[i])
        ft_printf("[%d]\n", pile.a_pile[i++]);
    sort_3nb(&pile, 3);
    i = 0;
    while(pile.a_pile[i])
        ft_printf("[%d]\n", pile.a_pile[i++]);
}