/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:07:58 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:29:01 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Si deja trie, je retourne, ou je remet dans l'ordre pour retourner
//	J'envoi 2 nodes sur la liste b, et je commence a trier
//	Je reset les couts de b vers a cette fois-ci
void	sorting(t_node **a_list, t_node **b_list)
{
	if (is_sorted(*a_list))
	{
		if (node_finder(*a_list, TOP)->data != find_minmax(*a_list).min)
			rotate_to_smallest(a_list);
		return ;
	}
	pb(a_list, b_list, PRINT);
	pb(a_list, b_list, PRINT);
	if ((*b_list)->data < (*b_list)->next->data && node_count(*a_list) > 4)
		rb(*b_list, PRINT);
	sorting_a2b(a_list, b_list);
	small_sort(a_list);
	sorting_b2a(b_list, a_list);
	if (is_sorted(*a_list))
		rotate_to_smallest(a_list);
}

//	Je creer une structure t_cost, et je set les couts des nodes de la premiere
// variable par rapport a la seconde variable
//	Je prends ensuite le node avec un Total Cost le plus faible
//	Puis je choisis la methode a adopter en fonction des variables etablies
//	Je Push le node dans la liste b, et je recommence
void	sorting_a2b(t_node **a_list, t_node **b_list)
{
	t_cost	cost;

	while (node_count(*a_list) > 3)
	{
		set_cost_a2b(a_list, b_list);
		*a_list = find_cheapest(a_list);
		cost = (*a_list)->cost;
		if (cost.rev == TOP && cost.r_rr == TOP)
			methods(*a_list, b_list, METHOD_1, A2B);
		else if (cost.rev == END && cost.r_rr == END)
			methods(*a_list, b_list, METHOD_2, A2B);
		else if (cost.rev == TOP && cost.r_rr == END)
			methods(*a_list, b_list, METHOD_3, A2B);
		else if (cost.rev == END && cost.r_rr == TOP)
			methods(*a_list, b_list, METHOD_4, A2B);
		pb(a_list, b_list, PRINT);
		*a_list = node_finder(*a_list, TOP);
	}
}

//	Je creer une structure t_cost, et je set les couts des nodes de la premiere
// variable par rapport a la seconde variable
//	Je prends ensuite le node avec un Total Cost le plus faible
//	Puis je choisis la methode a adopter en fonction des variables etablies
//	Je Push le node dans la liste b, et je recommence
void	sorting_b2a(t_node **b_list, t_node **a_list)
{
	t_cost	cost;

	while (*b_list)
	{
		set_cost_b2a(a_list, b_list);
		*b_list = find_cheapest(b_list);
		cost = (*b_list)->cost;
		if (cost.rev == TOP && cost.r_rr == TOP)
			methods(*b_list, a_list, METHOD_1, B2A);
		else if (cost.rev == END && cost.r_rr == END)
			methods(*b_list, a_list, METHOD_2, B2A);
		else if (cost.rev == TOP && cost.r_rr == END)
			methods(*b_list, a_list, METHOD_3, B2A);
		else if (cost.rev == END && cost.r_rr == TOP)
			methods(*b_list, a_list, METHOD_4, B2A);
		pa(a_list, b_list, PRINT);
		*b_list = node_finder(*b_list, TOP);
	}
}

//	Je repartie selon la methode la fonction a adopter
void	methods(t_node *node, t_node **list, int method, bool theway)
{
	t_cost	cost;

	cost = node->cost;
	node = node_finder(node, TOP);
	if (method == METHOD_1 && theway == A2B)
		method_1_a2b(node, list, cost);
	if (method == METHOD_2 && theway == A2B)
		method_2_a2b(node, list, cost);
	if (method == METHOD_3 && theway == A2B)
		method_3_a2b(node, list, cost);
	if (method == METHOD_4 && theway == A2B)
		method_4_a2b(node, list, cost);
	if (method == METHOD_1 && theway == B2A)
		method_1_b2a(node, list, cost);
	if (method == METHOD_2 && theway == B2A)
		method_2_b2a(node, list, cost);
	if (method == METHOD_3 && theway == B2A)
		method_3_b2a(node, list, cost);
	if (method == METHOD_4 && theway == B2A)
		method_4_b2a(node, list, cost);
}

// Petit algorithme de tri pour les listes inferieures ou egales a 3
void	small_sort(t_node **list)
{
	int	cost;

	node_finder(*list, TOP);
	if (node_count(*list) == 2 && (*list)->data > (*list)->next->data)
	{
		ra(*list, PRINT);
		return ;
	}
	if (node_count(*list) == 3 && !is_sorted(*list))
		sa(list, PRINT);
	cost = set_r_cost(find_smallest(list));
	if (node_count(node_finder(*list, TOP)) == 3 && is_sorted(*list)
		&& node_finder(*list, TOP)->data != find_minmax(*list).min)
	{
		if (cost == 1)
			ra(*list, PRINT);
		else if (cost == 2)
			rra(*list, PRINT);
	}
}
