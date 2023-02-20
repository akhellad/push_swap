/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:57:08 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/17 18:38:26 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int	check_if_ordered(t_pile *pile)
{
	size_t	i;

	i = 0;
	while (i < pile->tab_size - 1)
	{
		if (pile->tab[i] >= pile->tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int init_dir(t_init *init)
{
    char *line;
    line = get_next_line(STDIN_FILENO);
    while (line)
    {
        line = get_next_line(STDIN_FILENO);
        if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb") && \
ft_strcmp(line, "ss") && ft_strcmp(line, "pa") && ft_strcmp(line, "pb") && \
ft_strcmp(line, "ra") && ft_strcmp(line, "rb") && ft_strcmp(line, "rr") && \
ft_strcmp(line, "rra") && ft_strcmp(line, "rrb") && ft_strcmp(line, "rrr"))
		return (-1);
        if (add_dir(&init->dir, line))
            return (-1);
    }
    return (1);
}

int main(int ac, char **av)
{
    t_init init;
    if (--ac < 1)
        return (0);
    if (init_pile(ac, av, &init.a_pile, &init.b_pile))
        return (1);
    if (init_dir(&init))
        return (1);
    execute_dirs(init.dir, &init.a_pile, &init.b_pile);
    if (check_if_ordered(&init.a_pile) || init.b_pile.tab_size)
        write(1, "KO", 2);
    else
        write(1, "OK", 2);
    free_init(&init);
    return (0);
}