/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:17:53 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:50:28 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Calcul des differents parametres qui vont me permettre
// de calculer de couts total d'un noeud de 'a' en fonction de la liste 'b'
// le tout rentre dans une variable t_cost
void	set_cost_a2b(t_node **a_list, t_node **b_list)
{
	t_node	*a;

	a = *a_list;
	while (a)
	{
		a->cost.r = set_r_cost(a);
		a->cost.rr = set_rr_cost(a);
		a->cost.target = set_target_a2b(a, b_list);
		a = set_node_cost(a, b_list);
		a->cost.total_cost = set_total_cost(a);
		if (!a->next)
			break ;
		a = a->next;
	}
	*a_list = node_finder(a, TOP);
}

//	Calcul des differents parametres qui vont me permettre
// de calculer de couts total d'un noeud de 'b' en fonction de la liste 'a'
// le tout rentre dans une variable t_cost
void	set_cost_b2a(t_node **a_list, t_node **b_list)
{
	t_node	*b;

	b = node_finder(*b_list, TOP);
	while (b)
	{
		b->cost.r = set_r_cost(b);
		b->cost.rr = set_rr_cost(b);
		b->cost.target = set_target_b2a(b, a_list);
		b = set_node_cost(b, a_list);
		b->cost.total_cost = set_total_cost(b);
		if (!b->next)
			break ;
		b = b->next;
	}
	*b_list = node_finder(b, TOP);
}

//	J'etablis les priorites de mouvements grace a des booleens,
// en fonctions des resultats deja trouves, et de la dif de couts a ajouter
t_node	*set_node_cost(t_node *node, t_node **list)
{
	int	i;

	i = 0;
	if (node->cost.target >= node_count(*list) / 2 && node_count(*list) > 2)
	{
		node->cost.target = node_count(*list) - node->cost.target;
		node->cost.rev = END;
	}
	else
		node->cost.rev = TOP;
	if (node->cost.r <= node->cost.rr)
	{
		node->cost.dif = node->cost.r - node->cost.target;
		node->cost.r_rr = TOP;
	}
	else
	{
		node->cost.dif = node->cost.rr - node->cost.target;
		node->cost.r_rr = END;
	}
	if (node->cost.dif < 0)
		node->cost.dif *= -1;
	return (node);
}

//	Calcul du nombre total de couts de chaque noeud
// en fonction de tout les parametres calcules precedement
int	set_total_cost(t_node *node)
{
	int		total_cost;
	t_cost	cost;

	total_cost = 1;
	cost = node->cost;
	if (!cost.r_rr && !cost.rev)
	{
		if (cost.target >= cost.r)
			return (total_cost + cost.r + cost.dif);
		if (cost.target < cost.r)
			return (total_cost + cost.target + cost.dif);
	}
	if (cost.r_rr && cost.rev)
	{
		if (cost.target >= cost.rr)
			return (total_cost + cost.rr + cost.dif);
		if (cost.target < cost.rr)
			return (total_cost + cost.target + cost.dif);
	}
	if (!cost.r_rr && cost.rev)
		return (total_cost + cost.r + cost.target);
	if (cost.r_rr && !cost.rev)
		return (total_cost + cost.rr + cost.target);
	return (total_cost);
}
