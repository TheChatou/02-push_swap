/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:02:59 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 14:10:02 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Trouver le noeud avec la plus grosse data
t_node	*find_biggest(t_node **list)
{
	t_node	*biggest;

	biggest = *list;
	while (*list)
	{
		if ((*list)->data == find_minmax(*list).max)
			biggest = *list;
		if (!(*list)->next)
			break ;
		*list = (*list)->next;
	}
	return (biggest);
}

//	Trouver le noeud avec la plus petite data
t_node	*find_smallest(t_node **list)
{
	t_node	*smallest;

	smallest = *list;
	while (*list)
	{
		if ((*list)->data == find_minmax(*list).min)
			smallest = *list;
		if (!(*list)->next)
			break ;
		*list = (*list)->next;
	}
	return (smallest);
}

//	Rotate la list pour remonter le node le plus gros en haut
t_node	*rotate_to_biggest(t_node **list)
{
	if ((*list)->cost.rev)
	{
		while ((*list)->data > (*list)->next->data)
		{
			rrb(*list, PRINT);
			*list = node_finder(*list, TOP);
		}
		rrb(*list, PRINT);
	}
	else
	{
		while ((*list)->data > (*list)->next->data)
		{
			rb(*list, PRINT);
			*list = node_finder(*list, TOP);
		}
		rb(*list, PRINT);
	}
	*list = node_finder(*list, TOP);
	return ((*list));
}

//	Rotate la list pour remonter le node le plus petit en haut
t_node	*rotate_to_smallest(t_node **list)
{
	int		i;
	int		nodes;

	*list = node_finder(*list, TOP);
	while ((*list)->next)
	{
		(*list)->cost.r = set_r_cost(*list);
		(*list) = (*list)->next;
	}
	(*list)->cost.r = set_r_cost(*list);
	*list = node_finder(*list, TOP);
	*list = find_smallest(list);
	nodes = node_count(node_finder(*list, TOP));
	i = 0;
	while ((*list)->cost.r > nodes / 2 && nodes - (*list)->cost.r != i)
	{
		rra(*list, PRINT);
		i++;
	}
	while ((*list)->cost.r <= nodes / 2 && (*list)->cost.r != i)
	{
		ra(*list, PRINT);
		i++;
	}
	return ((*list));
}
