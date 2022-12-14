#include "/home/akhellad/Documents/push_swap/includes/push_swap.h"

/*
** copie une chaine de caractère jusu'au caractère stop
*/
char				*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*pt;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	if (!(pt = malloc((i + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

/*
** Compte comben il y a de nombres totaux dans les arguments
*/

size_t  count_pile_size(int ac, char **av)
{
    size_t  i;
    size_t  n;
    size_t  size;

    size = 0;
    i = 0;

    while (i < (size_t)ac)
    {
        n = 0;
        while (av[i][n])
        {
            if((n == 0 || av[i][n - 1] == ' ') && av[i][n] != ' ')
                size ++;
            n ++;
        }
        i ++;
    }
    return (size);
}

/*
** remplis la ligne d'une pile avec un argument
*/

int     fill_pile_arg(char *argv, t_pile *pile, size_t *pile_nb)
{
    int nbr;
    char *str;

    while (*argv)
    {
        while(*argv && *argv == ' ')
            argv ++;
        if (!*argv)
            break ;
        str = ft_strdup_char(argv, ' ');
        if (ft_atoi(str, &nbr))
        {
            free(str);
            return (1);
        }
        free(str);
        if (check_double(pile, nbr))
            return (1);
        pile->tab[(*pile_nb)++] = nbr;
        pile->tab_size++;
        while (*argv && *argv != ' ')
            argv++;
    }
    return (0);
}

/*
** remplie la pile a
*/

int     fill_pile(int ac, char **av, t_pile *pile)
{
    size_t i;
    size_t n;
    char *str;

    i = 0;
    n = 0;
    while(i < (size_t)ac)
    {
        str = av[i];
        if (fill_pile_arg(str, pile, &n))
            return 1;
        i ++;
    }
    return (0);
}

/*
** Initialise et alloue la taille necessecaire pour la pile a et b avec les arguments passés en paramètre 
*/

int					init_pile(int argc, char **argv, t_pile *a_pile, t_pile *b_pile)
{
	size_t		pile_size;

	pile_size = count_pile_size(argc, argv);
	if (!(a_pile->tab = malloc(sizeof(int) * pile_size)))
		return (write(STDERR_FILENO, "Error\n", 6));
	if (!(b_pile->tab = malloc(sizeof(int) * pile_size)))
	{
		free(a_pile->tab);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	a_pile->max_tab_size = pile_size;
	b_pile->max_tab_size = pile_size;
	a_pile->tab_size = 0;
	b_pile->tab_size = 0;
	if (fill_pile(argc, argv, a_pile))
	{
		free(a_pile->tab);
		free(b_pile->tab);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}