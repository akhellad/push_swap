#include "push_swap.h"

int main(int ac, char **av)
{
    t_init  init;

    if(--ac < 1 && ac == 1)
        return (0);
    else if (init_pile(ac, &av[1], &init.a_pile, &init.b_pile))
        return (1);
    init.dir = NULL;
    if(check_if_ordered(&init.a_pile, ASC) && resolve(&init))
    {
        free_direction(init.dir);
        write(STDERR_FILENO, "Error\n", 6);
        return (1);
    }
    print_direction(init.dir);
	free_init(&init);
	return (0); 
}