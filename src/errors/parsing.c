/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:51:50 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 14:03:17 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Verification des erreurs & initialisation de la liste
bool	stack_init(t_node **list, char **argv, bool split)
{
	long int	nbr;
	int			i;

	i = 0;
	if (!split)
		i++;
	while (argv[i])
	{
		if (!error_syntaxe(argv[i]))
			return (ft_putstr_fd("Error\n", 2),
				error_free(*list, NULL, argv, split), 0);
		nbr = ft_atol(argv[i]);
		if ((nbr > INT_MAX || nbr < INT_MIN)
			|| !error_double((int)nbr, *list))
			return (ft_putstr_fd("Error\n", 2),
				error_free(*list, NULL, argv, split), 0);
		add_node(nbr, list);
		i++;
	}
	return (1);
}

//	Ajout d'un noeud unique (ATTENTION au CALLOC a free plus tard)
void	add_node(int nbr, t_node **list)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = nbr;
	if (*list == NULL)
	{
		*list = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = node_finder(*list, END);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

//	Verification de la syntaxe de l'argument du main
int	error_syntaxe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		{
			if (i != 0)
				return (0);
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//	Verification en cas de doublons
int	error_double(int nbr, t_node *a)
{
	t_node	*tmp;

	tmp = node_finder(a, TOP);
	while (tmp)
	{
		if (nbr == tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
