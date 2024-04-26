/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_b2a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:32 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:54:18 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Methode 1 : Double Rotation vers le haut
void	method_1_b2a(t_node *node, t_node **a_list, t_cost cost)
{
	int	i;
	int	move;

	i = 0;
	node = node_finder(node, TOP);
	if (cost.r > cost.target)
		move = cost.target;
	else
		move = cost.r;
	while (cost.target && cost.r && i < move)
	{
		rr(&node, a_list, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.r)
			ra(*a_list, PRINT);
		else
			rb(node, PRINT);
		i++;
	}
}

//	Methode 2 : Double Rotation vers le bas
void	method_2_b2a(t_node *node, t_node **a_list, t_cost cost)
{
	int	i;
	int	move;

	i = 0;
	node = node_finder(node, TOP);
	if (cost.rr > cost.target)
		move = cost.target;
	else
		move = cost.rr;
	while (cost.target && cost.rr && i < move)
	{
		rrr(&node, a_list, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.rr)
			rra(*a_list, PRINT);
		else
			rrb(node, PRINT);
		i++;
	}
}

//	Methode 3 : Rotation de 'b' vers le bas et Rotation de 'a' vers le haut
void	method_3_b2a(t_node *node, t_node **a_list, t_cost cost)
{
	int	i;
	int	move;

	i = 0;
	node = node_finder(node, TOP);
	if (cost.rr > cost.target)
		move = cost.target;
	else
		move = cost.rr;
	while (cost.target && cost.rr && i < move)
	{
		ra(*a_list, PRINT);
		rrb(node, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.rr)
			ra(*a_list, PRINT);
		else
			rrb(node, PRINT);
		i++;
	}
}

//	Methode 4 : Rotation de 'b' vers le haut et Rotation de 'a' vers le bas
void	method_4_b2a(t_node *node, t_node **a_list, t_cost cost)
{
	int	i;
	int	move;

	i = 0;
	node = node_finder(node, TOP);
	if (cost.r > cost.target)
		move = cost.target;
	else
		move = cost.r;
	while (cost.target && cost.r && i < move)
	{
		rra(*a_list, PRINT);
		rb(node, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.r)
			rra(*a_list, PRINT);
		else
			rb(node, PRINT);
		i++;
	}
}
