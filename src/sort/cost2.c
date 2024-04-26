/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:24:59 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:41:37 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Chercher l'emplacement cible pour le tri, de a vers b
int	set_target_a2b(t_node *a_node, t_node **b_list)
{
	int				target;
	t_node			*b_top;
	t_node			*b_next;
	static t_minmax	minmax;

	minmax = find_minmax(*b_list);
	target = 0;
	b_top = node_finder(*b_list, TOP);
	while (b_top)
	{
		if (!b_top->next)
			b_next = *b_list;
		else
			b_next = b_top->next;
		if ((b_top->data == minmax.max && a_node->data < minmax.min)
			|| (a_node->data > minmax.max && b_top->data == minmax.max))
			break ;
		target++;
		if (a_node->data < b_top->data && a_node->data > b_next->data)
			break ;
		b_top = b_top->next;
	}
	if (!b_top)
		target = 0;
	return (target);
}

//	Chercher l'emplacement cible pour le tri, de b vers a
int	set_target_b2a(t_node *b_node, t_node **a_list)
{
	int				target;
	static t_minmax	minmax;
	t_node			*a_next;
	t_node			*a_top;

	minmax = find_minmax(*a_list);
	target = 0;
	a_top = node_finder((*a_list), TOP);
	while (a_top)
	{
		if (!a_top->next)
			a_next = *a_list;
		else
			a_next = a_top->next;
		if ((a_top->data == minmax.min && b_node->data < minmax.min)
			|| (a_top->data == minmax.min && b_node->data > minmax.max))
			break ;
		target++;
		if (b_node->data > a_top->data && b_node->data < a_next->data)
			break ;
		a_top = a_top->next;
	}
	if (!a_top)
		target = 0;
	return (target);
}

//	Calcul du nombre de ROTATE necessaires en fonction du noeud
int	set_r_cost(t_node *node)
{
	int	r;

	r = -1;
	while (node)
	{
		r++;
		if (node->prev == NULL)
			break ;
		node = node->prev;
	}
	return (r);
}

//	Calcul du nombre de REVERSE ROTATE necessaires en fonction du noeud
int	set_rr_cost(t_node *node)
{
	int	rr;

	rr = 0;
	while (node)
	{
		rr++;
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	return (rr);
}
