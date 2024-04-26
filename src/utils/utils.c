/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:52:27 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 14:10:45 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Super fonction pour retrouver le premier noeud, ou le dernier,
// selon un booleen avec une macro "TOP" ou "END"
t_node	*node_finder(t_node *node, bool where)
{
	if (!node)
		return (NULL);
	if (!where)
	{
		while (node->prev)
			node = node->prev;
		return (node);
	}
	else
	{
		while (node->next)
			node = node->next;
		return (node);
	}
}

//	Compter le nombre de noeuds dans une liste
int	node_count(t_node *node)
{
	int	i;

	i = 0;
	node = node_finder(node, TOP);
	while (node)
	{
		i++;
		node = node->next;
	}
	node = node_finder(node, TOP);
	return (i);
}

//	Est-ce que la liste est triee, du plus grand au plus petit
bool	is_rev_sorted(t_node *node)
{
	int	ref;

	node = find_biggest(&node);
	ref = node->data;
	node = node->next;
	while (node->data != ref)
	{
		if (node->next && node->data < node->next->data)
			return (0);
		if (!node->next)
		{
			node = node_finder(node, TOP);
			break ;
		}
		node = node->next;
	}
	return (1);
}

//	Est-ce que la liste est triee, du plus petit au plus grand
bool	is_sorted(t_node *node)
{
	int	first;
	int	last;

	last = node_finder(node, END)->data;
	first = node_finder(node, TOP)->data;
	node = node_finder(node, TOP);
	while (node)
	{
		if (!node->next)
			break ;
		if (last > first && last != find_minmax(node).max
			&& first != find_minmax(node).min)
			return (0);
		if (node->data < node->next->data
			|| (node->data == find_minmax(node).max
				&& node->next->data == find_minmax(node).min))
			node = node->next;
		else
			return (0);
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	sign;
	long	cti;

	i = 0;
	sign = 1;
	cti = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		cti *= 10;
		cti += nptr[i] - '0';
		i++;
	}
	cti *= sign;
	return (cti);
}
