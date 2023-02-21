/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:56:24 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/21 17:24:42 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_init			init;

	if (--argc < 1)
		return (0);
	if (init_pile(argc, &argv[1], &init.a_pile, &init.b_pile))
		return (1);
	init.dir = NULL;
	if (check_if_ordered(&init.a_pile, ASC) && resolve(&init))
	{
		free_direction(init.dir);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	print_dirs(init.dir);
	free_init(&init);
	return (0);
}
