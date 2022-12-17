#include "push_swap.h"

int				can_pb(t_pile *a_pile, t_pile *b_pile)
{
	if (a_pile->tab_size)
		return (0);
	if (b_pile->tab_size < 2)
		return (1);
	else if (a_pile->tab[0] > b_pile->tab[0])
	{
		if (a_pile->tab[0] < b_pile->tab[b_pile->tab_size - 1] &&
b_pile->tab[0] < b_pile->tab[b_pile->tab_size - 1])
			return (1);
		else if (a_pile->tab[0] > b_pile->tab[b_pile->tab_size - 1] &&
b_pile->tab[0] > b_pile->tab[b_pile->tab_size - 1])
			return (1);
	}
	else if (a_pile->tab[0] < b_pile->tab[b_pile->tab_size - 1] &&
b_pile->tab[b_pile->tab_size - 1] < b_pile->tab[0])
		return (1);
	return (0);
}

size_t		closer_pos_to_inf(int nb, t_pile *pile)
{
	size_t		pos;

	pos = 0;
	if (nb > pile->tab[0] && nb < pile->tab[pile->tab_size - 1])
		return (pos);
	while (pos < pile->tab_size && nb > pile->tab[pos])
		pos++;
	if (pos != pile->tab_size)
	{
		while (pos < pile->tab_size - 1 && nb < pile->tab[pos])
			pos++;
		if (pos == pile->tab_size - 1 && pile->tab[pos] > nb)
			pos = pile->tab_size;
	}
	if (pos == pile->tab_size)
	{
		pos = 1;
		while (pos < pile->tab_size && pile->tab[pos - 1] > pile->tab[pos])
			pos++;
	}
	if (pos == pile->tab_size)
		pos = 0;
	return (pos);
}

size_t			less_mvt_at_begin(size_t minimal_mvt, size_t *min_mvt, t_pile *a_pile, t_pile *b_pile)
{
	size_t		i;
	size_t		min;
	size_t		tmp[2];

	if (minimal_mvt > b_pile->tab_size / 2)
		minimal_mvt = b_pile->tab_size - minimal_mvt;
	min = minimal_mvt + 1;
	i = 0;
	while (++i < a_pile->tab_size && i < minimal_mvt)
	{
		tmp[0] = closer_pos_to_inf(a_pile->tab[i], b_pile);
		tmp[1] = b_pile->tab_size - tmp[0];
		if ((tmp[0] > b_pile->tab_size / 2 && i + tmp[1] < min) ||
(tmp[0] >= i && tmp[0] < min) || (tmp[0] < i && i < min))
			*min_mvt = tmp[0];
		if (tmp[0] > b_pile->tab_size / 2 && i + tmp[1] < min)
			min = i + tmp[1];
		else if (tmp[0] >= i && tmp[0] < min)
			min = tmp[0];
		else if (tmp[0] < i && i < min)
			min = i;
	}
	return (min);
}

size_t			less_mvt_at_end(size_t minimal_mvt, size_t *min_mvt, t_pile *a_pile, t_pile *b_pile)
{
	size_t		i;
	size_t		m;
	size_t		t[2];

	if (minimal_mvt > b_pile->tab_size / 2)
		minimal_mvt = b_pile->tab_size - minimal_mvt;
	m = minimal_mvt + 1;
	i = a_pile->tab_size;
	while (--i > 0 && (a_pile->tab_size - i) < minimal_mvt)
	{
		t[0] = closer_pos_to_inf(a_pile->tab[i], b_pile);
		t[1] = b_pile->tab_size - t[0];
		if ((t[0] > b_pile->tab_size / 2 && t[1] >= (a_pile->tab_size - i) &&
t[1] < m) || (t[0] > b_pile->tab_size / 2 && t[1] < (a_pile->tab_size - i) &&
(a_pile->tab_size - i) < m) || ((a_pile->tab_size - i) + t[0] < m))
			*min_mvt = t[0];
		if (t[0] > b_pile->tab_size / 2 && t[1] >= (a_pile->tab_size - i) && t[1] < m)
			m = t[1];
		else if (t[0] > b_pile->tab_size / 2 &&
t[1] < (a_pile->tab_size - i) && (a_pile->tab_size - i) < m)
			m = (a_pile->tab_size - i);
		else if ((a_pile->tab_size - i) + t[0] < m)
			m = (a_pile->tab_size - i) + t[0];
	}
	return (m);
}