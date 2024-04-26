/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:09:53 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 13:36:49 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Toutes les fonctions ROTATE
//	Ajout d'un booleen pour les Bonus,
// pour savoir si j'imprime les instructions
void	rotate(t_node *a)
{
	t_node	*first;
	t_node	*last;
	t_node	*tmp;

	first = node_finder(a, TOP);
	last = node_finder(a, END);
	tmp = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	tmp->prev = NULL;
}

void	ra(t_node *a, bool checker)
{
	rotate(a);
	if (!checker)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_node *b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **a, t_node **b, bool checker)
{
	if (*a)
		rotate(*a);
	else
		return ;
	if (*b)
		rotate(*b);
	else
		return ;
	if (!checker)
		ft_putstr_fd("rr\n", 1);
}
