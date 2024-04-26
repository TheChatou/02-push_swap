/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:09:53 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 14:48:59 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Toutes les fonctions REVERSE ROTATE
//	Ajout d'un booleen pour les Bonus,
// pour savoir si j'imprime les instructions
void	reverse_rotate(t_node *a)
{
	t_node	*first;
	t_node	*last;
	t_node	*tmp;

	if (a->next == NULL && a->prev == NULL)
		return ;
	first = node_finder(a, TOP);
	last = node_finder(a, END);
	tmp = last->prev;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	tmp->next = NULL;
}

void	rra(t_node *a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node *b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **a, t_node **b, bool checker)
{
	if (*a)
		reverse_rotate(*a);
	else
		return ;
	if (*b)
		reverse_rotate(*b);
	else
		return ;
	if (!checker)
		ft_putstr_fd("rrr\n", 1);
}
