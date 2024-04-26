/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:16:08 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 14:09:11 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Fonction pour liberer l'espace alloue
void	error_free(t_node *a, t_node *b, char **argv, bool split)
{
	if (a != NULL)
		node_clear(a);
	if (b != NULL)
		node_clear(b);
	free_argv(argv, split);
	exit(0);
}

//	Free argv si il y a eu utilisation de la fonction split
void	free_argv(char **argv, bool split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

//	Free noeud par noeud
void	node_clear(t_node *node)
{
	t_node	*tmp;

	node = node_finder(node, TOP);
	if (!node)
		return ;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
