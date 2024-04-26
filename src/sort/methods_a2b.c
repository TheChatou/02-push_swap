/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_a2b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:32 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:52:53 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Methode 1 : Double Rotation vers le haut
void	method_1_a2b(t_node *node, t_node **b_list, t_cost cost)
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
		rr(&node, b_list, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.r)
			rb(*b_list, PRINT);
		else
			ra(node, PRINT);
		i++;
	}
}

//	Methode 2 : Double Rotation vers le bas
void	method_2_a2b(t_node *node, t_node **b_list, t_cost cost)
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
		rrr(&node, b_list, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.rr)
			rrb(*b_list, PRINT);
		else
			rra(node, PRINT);
		i++;
	}
}

//	Methode 3 : Rotation de 'a' vers le bas et Rotation de 'b' vers le haut
void	method_3_a2b(t_node *node, t_node **b_list, t_cost cost)
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
		rb(*b_list, PRINT);
		rra(node, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.rr)
			rb(*b_list, PRINT);
		else
			rra(node, PRINT);
		i++;
	}
}

//	Methode 4 : Rotation de 'a' vers le haut et Rotation de 'b' vers le bas
void	method_4_a2b(t_node *node, t_node **b_list, t_cost cost)
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
		rrb(*b_list, PRINT);
		ra(node, PRINT);
		i++;
	}
	i = 0;
	while (cost.dif != i)
	{
		if (cost.target > cost.r)
			rrb(*b_list, PRINT);
		else
			ra(node, PRINT);
		i++;
	}
}
