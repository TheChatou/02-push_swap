/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:00:30 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:36:57 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Toutes les fonctions SWAP
//	Ajout d'un booleen pour les Bonus,
// pour savoir si j'imprime les instructions
void	swap(t_node **a)
{
	t_node	*to_swap1;
	t_node	*to_swap2;
	t_node	*tmp;

	to_swap1 = node_finder(*a, TOP);
	to_swap2 = to_swap1->next;
	tmp = to_swap2->next;
	to_swap2->next = to_swap1;
	to_swap1->next = tmp;
	to_swap1->prev = to_swap2;
	to_swap2->prev = NULL;
	tmp->prev = to_swap1;
}

void	sa(t_node **a, bool checker)
{
	swap(a);
	if (!checker)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **a, t_node **b, bool checker)
{
	if (*a)
		swap(a);
	else
		return ;
	if (*b)
		swap(b);
	else
		return ;
	if (!checker)
		ft_putstr_fd("ss\n", 1);
}
