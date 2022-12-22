#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ASC		0
# define DESC		1

# define DEPTH		5

typedef struct s_pile
{
    int *tab;
    size_t tab_size;
    size_t max_tab_size;
}           t_pile;

typedef struct s_dir
{
    char    *line;
    void    *next;
    void    *prev;
}           t_dir;

typedef struct s_init
{
    t_pile   a_pile;
    t_pile   b_pile;
    t_dir  *dir;
    int     debug;
}           t_init;

typedef struct s_cond
{
    t_pile *a_pile;
    t_pile *b_pile;
    t_dir  *dir;
    t_dir  *last_dir;
    void    *next; 
}           t_cond;

int         init_pile(int ac, char **av, t_pile *a_pile, t_pile *b_pile);
size_t      count_pile_size(int ac, char **av);
char	    *ft_strdup_char(const char *str, char stop);
int         check_double(t_pile *pile, int nbr);
int         check_if_ordered(t_pile *pile, int order);
t_pile      *new_empty_pile(size_t max_size);
t_pile      *pile_copy(t_pile *pile);
void        rrt(t_pile *pile);
t_cond      *new_empty_condition(t_pile *a_pile, t_pile *b_pile, size_t maxsize);
int		    ft_strcmp(const char *s1, const char *s2);
void	    rt(t_pile *pile);
void	    pt(t_pile *pile1, t_pile *pile2);
void	    st(t_pile *pile);
void	    free_condition(t_cond *cond);
void	    free_pile(t_pile *pile);
void	    free_init(t_init *init);
void	    execute_dirs(t_dir *instr, t_pile *stack_a, t_pile *stack_b);
t_dir	    *add_dir(t_dir **dirs, char *line);
t_dir	    *add_n_dirs(t_dir **dir, char *line, size_t n);
t_dir	    *copy_dir(t_dir *dir);
t_dir	    *copy_and_concat_dir(t_dir **instr, t_dir *new);
int		    create_condition_resolution(t_cond **condition);
t_dir	    *rotate_a(t_cond *stt, size_t min[2], size_t min_mvt[2]);
t_dir	    *rotate(t_cond *stt);
int		    large_resolve(t_cond *conds);
int		    reverse_rotate_bruteforce_a(t_cond **new_conds, t_cond *tmp, size_t pos[2], t_pile *p_pile);
int		    rotate_bruteforce_a(t_cond **new_conds, t_cond *tmp, size_t pos[2], t_pile *b_pile);
int		    bruteforce_choice_a(t_cond **new_conds, t_cond *tmp, size_t pos[2], t_pile *b_pile);
int		    check_bruteforce_solution(t_cond *conds, t_cond **result);
t_cond	    *pick_bruteforce_solution(t_cond *conds, size_t pos[2], t_pile *b_pile);
int		    bruteforce_order_a(t_init *init);
void	    calcul_sort_a(size_t *pos, size_t *mvt, t_pile *a_pile, t_pile *b_pile);
void    	calcul_sort_b(size_t *pos, size_t *mvt, t_pile *b_pile);
int		    align_a_pile(t_init *init);
int		    align_b_pile(t_init *init);
void	    free_direction(t_dir *dir);
void	    free_pile(t_pile *pile);
void	    free_init(t_init *init);
t_cond	    *add_condition(t_cond **conds, t_cond *cond_from);
void	    free_condition(t_cond *conds);
t_cond	    *new_condition_direction(t_cond **conds, t_cond *old_cond, char *line);
int		    can_pb(t_pile *a_pile, t_pile *b_pile);
size_t	    closer_pos_to_inf(int nb, t_pile *pile);
size_t	    less_mvt_at_begin(size_t minimal_mvt, size_t *min_mvt, t_pile *a_pile, t_pile *b_pile);
size_t	    less_mvt_at_end(size_t minimal_mvt, size_t *min_mvt, t_pile *a_pile, t_pile *b_pile);
size_t	    count_dir(t_dir *dir);
int		    pick_solution(t_init *init, t_cond *conds);
int		    realign_and_sort_a(t_init *init);
int		    resolve(t_init *init);
int			ft_atoi(const char *str, int *num);
char        *ft_strdup(const char *src);
size_t	    ft_strlen(const char *str);
void	    print_dirs(t_dir *dir);
void	    print_dir(t_dir *dir);

#endif

