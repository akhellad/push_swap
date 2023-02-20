/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:57:06 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/17 18:40:02 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int		*tab;
	size_t	tab_size;
	size_t	max_tab_size;
}			t_pile;

typedef struct s_dir
{
	char	*line;
	void	*next;
	void	*prev;
}			t_dir;

typedef struct s_init
{
	t_pile	a_pile;
	t_pile	b_pile;
	t_dir	*dir;
	int		debug;
}			t_init;

typedef struct s_cond
{
	t_pile	*a_pile;
	t_pile	*b_pile;
	t_dir	*dir;
	t_dir	*last_dir;
	void	*next;
}			t_cond;

int	    init_pile(int argc, char **argv, t_pile *a_pile, t_pile *b_pile);
void	free_init(t_init *init);
void	execute_dirs(t_dir *instr, t_pile *stack_a, t_pile *stack_b);
t_dir	*add_dir(t_dir **dirs, char *line);
int	    ft_strcmp(const char *s1, const char *s2);
void	rt(t_pile *pile);
void	pt(t_pile *pile1, t_pile *pile2);
void	st(t_pile *pile);
void	rrt(t_pile *pile);
void	free_direction(t_dir *dir);
char	*ft_strdup(const char *src);
int	    ft_atoi(const char *str, int *num);
int	    check_double(t_pile *pile, int nbr);

#endif