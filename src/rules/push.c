/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:00 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:36:13 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Toutes les fonctions PUSH
//	Ajout d'un booleen pour les Bonus,
// pour savoir si j'imprime les instructions
void	push(t_node **a, t_node **b)
{
	t_node	*tmp;

	*a = node_finder(*a, 0);
	*b = node_finder(*b, 0);
	if (*a)
		tmp = (*a)->next;
	else
		return ;
	if (!*b)
	{
		tmp->prev = NULL;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
	else
	{
		if (tmp)
			tmp->prev = NULL;
		(*a)->next = *b;
		(*a)->prev = NULL;
		(*b)->prev = *a;
		*b = *a;
		*a = tmp;
	}
}

void	pb(t_node **a, t_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_putstr_fd("pb\n", 1);
}

void	pa(t_node **a, t_node **b, bool checker)
{
	push(b, a);
	if (!checker)
		ft_putstr_fd("pa\n", 1);
}
