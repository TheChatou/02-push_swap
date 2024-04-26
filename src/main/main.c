/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:40:48 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:34:47 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Premiere verification du bon nombre d'arguments
//	Puis utilisation de la fonction split si les nombre sont "",
// (ATTENTION au MALLOC), ajout d'un booleen si split est utiliser pour free
//	Puis verification des erreurs & initialisation de la liste
//	Puis le tri commence avec les fonctions adaptees
int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	bool		split;

	a = NULL;
	b = NULL;
	split = 0;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (2 == argc)
	{
		argv = ft_split(argv[1], ' ');
		split = 1;
	}
	stack_init(&a, argv, split);
	if (node_count(a) == 1)
		return (error_free(a, b, argv, split), 0);
	if (node_count(a) <= 3)
		small_sort(&a);
	else
		sorting(&a, &b);
	error_free(a, b, argv, split);
	exit(0);
}
