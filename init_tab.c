#include "push_swap.h"


int check_doubl(char **tmp, int count)
{
    int n = 0;
    int i = 1;
    while(tmp[n])
    {
        while(tmp[i])
        {
        if(ft_atoi(tmp[n]) == ft_atoi(tmp[i]))
        {
            return (1);
        }
        i ++;
        }
        n ++;
        i = n + 1;
    }
    return (0);
}

int check_digit(int count, char **tmp)
{
    int i;
    int n;

    i = 1;
    n = 0;
    while(i < count)
    {
        while(tmp[i][n])
        {
            if(!ft_isdigit(tmp[i][n]) && tmp[i][n] != '-')
            {
                return (1);
            }
            n ++;
        }
        n = 0;
        i ++;
    }
    return (0);
}

int count_digit(char **tmp)
{
    int i;

    i = 0;
    while(tmp[i])
        i++;
    return(i);
}

char **parc(int ac, char **av, char **tmp)
{
    char    *tab;
    int     i;
    int count;

    while(av[i])
    {
        count += ft_strlen(av[i]);
        i ++;
    }
    tab = malloc(sizeof(char) * count);
    i = 1;
    while(av[i])
    {
        tab = ft_strjoin(tab, av[i]);
        tab = ft_strjoin(tab, " ");
        i ++;
    }
    tmp = ft_split(tab, ' ');
    if(!tmp)
        return (0);
    i = 0;
    free(tab);
    return (tmp);
}

int *char_to_int(char **tmp, int count, t_tab *tab)
{
    int *parse;
    int i;
    long long n;

    i = 0;
    parse = malloc(sizeof(int) * count + 1);
    while(tmp[i])
    {
        n = ft_atoi(tmp[i]);
        if (n > 2147483647 || n < -2147483648)
            ft_printf("Error\n");
        parse[i] = (int)n;
        i ++;
    }
    tab->a_top = i - 1;
    return (parse);
}