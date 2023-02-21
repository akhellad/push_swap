/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:57:08 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/21 17:04:25 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int pile_contains(t_pile *pile, int num)
{
	size_t	i;

	i = 0;
	while (i < pile->tab_size)
	{
		if (pile->tab[i++] == num)
			return (1);
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
    while (line != NULL)
    {
        if (ft_strcmp(line, "sa\n") && ft_strcmp(line, "sb\n") && \
ft_strcmp(line, "ss\n") && ft_strcmp(line, "pa\n") && ft_strcmp(line, "pb\n") && \
ft_strcmp(line, "ra\n") && ft_strcmp(line, "rb\n") && ft_strcmp(line, "rr\n") && \
ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n") && ft_strcmp(line, "rrr\n"))
        {
            write(1, "Error\n", 6);
		    return (-1);
        }
        if (add_dir(&init->dir, line))
            return (-1);
        free (line);
        line = get_next_line(STDIN_FILENO);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_init init;

    if (--ac < 1)
        return (0);
    else if (init_pile(ac, &av[1], &init.a_pile, &init.b_pile))
        return (1);
    if (init_dir(&init))
        return (1);
    execute_dirs(init.dir, &init.a_pile, &init.b_pile);
    if (check_if_ordered(&init.a_pile) || init.b_pile.tab_size)
        write(1, "KO\n", 3);
    else
        write(1, "OK\n", 3);
    free_init(&init);
    return (0);
}