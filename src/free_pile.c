#include "./includes/push_swap.h"

void			free_direction(t_dir *dir)
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

void			free_pile(t_pile *pile)
{
	free(pile->tab);
	free(pile);
}

void			free_init(t_init *init)
{
	free_direction(init->dir);
	free(init->a_pile.tab);
	free(init->b_pile.tab);
}
