/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:53:33 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 14:09:42 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Trouver la data max et la data min
t_minmax	find_minmax(t_node *node)
{
	int	min;
	int	max;

	node = node_finder(node, TOP);
	if (!node)
		return ((t_minmax){0, 0});
	max = node->data;
	if (node->next)
		min = node->next->data;
	else
		min = node_finder(node, TOP)->data;
	if (node_count(node) == 2 && min < max)
		return ((t_minmax){min, max});
	else if (node_count(node) == 2 && min > max)
		return ((t_minmax){max, min});
	while (node)
	{
		if (node->data < min)
			min = node->data;
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return ((t_minmax){min, max});
}

//	Trouver le noeud avec le cout le moins cher
t_node	*find_cheapest(t_node **list)
{
	t_node	*cheapest;

	cheapest = *list;
	while (*list)
	{
		if ((*list)->cost.total_cost < cheapest->cost.total_cost)
			cheapest = *list;
		(*list) = (*list)->next;
	}
	return (cheapest);
}
