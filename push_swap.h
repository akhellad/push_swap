#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <unistd.h>

typedef struct s_tab
{
    int *a_pile;
    int *b_pile;
    int a_top;
    int b_top;
}       t_tab;

int *char_to_int(char **tmp, int count, t_tab *tab);
char **parc(int ac, char **av, char **tmp);
int count_digit(char **tmp);
int check_digit(int count, char **tmp);
int check_doubl(char **tmp, int count);
int	check_if_sorted(int *t, int top);
void	rrb(int *tab, int top, char c);
void	rra(int *tab, int top, char c);
void	rr(int *t_a, int top_a, int *t_b, int top_b);
void	rb(int *t, int top, char c);
void	ra(int *tab_a, int top_a, char c);
void	sa(int *t, int top, char cn);
void	sb(int *t, int top, char cn);
void	ss(int *t_a, int top_a, int *t_b, int top_b);
void	pb(int *t_a, int *top_a, int *t_b, int *top_b);
void	pa(int *t_a, int *top_a, int *t_b, int *top_b);

#endif

