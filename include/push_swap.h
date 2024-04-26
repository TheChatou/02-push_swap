/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:43:47 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/26 18:17:28 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

////////////////////////////////////////////////////////////////////////////////
//	LIBS	 ///////////////////////////////////////////////////////////////////
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

////////////////////////////////////////////////////////////////////////////////
//	MACROS	 ///////////////////////////////////////////////////////////////////
# define TOP		0
# define END		1

# define A2B		0
# define B2A		1

# define PRINT		0
# define CHECK		1

# define METHOD_1	1
# define METHOD_2	2
# define METHOD_3	3
# define METHOD_4	4
# define METHOD_5	5

////////////////////////////////////////////////////////////////////////////////
//	STRUCTS		////////////////////////////////////////////////////////////////
//	t_cost	//
///	target		: emplacement dans la liste triee du node a deplacer
///	rev			: booleen pour la target (vers le haut ou vers le bas)
///	r			: emplacement du noeud a deplacer dans la liste (haut vers bas)
///	rr			: emplacement du noeud a deplacer dans la liste (bas vers haut)
///	r_rr		: booleen pour le noeud (vers le haut ou vers le bas)
///	dif			: difference entre les couts de deplacement du noeud
//				et de la target dans la liste
//	total_cost	: nombre de couts total optimal par noeud
typedef struct s_cost
{
	int				target;
	int				r;
	int				rr;
	int				dif;
	bool			r_rr;
	bool			rev;
	int				total_cost;
}					t_cost;

typedef struct s_node
{
	int				data;
	bool			split;
	struct s_node	*prev;
	struct s_node	*next;
	t_cost			cost;
}					t_node;

typedef struct s_minmax
{
	int				min;
	int				max;
}					t_minmax;

////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS 	////////////////////////////////////////////////////////////////
//	/errors		////////////////////////////////////////////////////////////////
//	/errors.c	/
void		error_free(t_node *a, t_node *b, char **argv, bool split);
void		free_argv(char **argv, bool split);
void		node_clear(t_node *node);

//	/parsing.c	/
bool		stack_init(t_node **list, char **argv, bool split);
void		add_node(int nbr, t_node **list);
int			error_syntaxe(char *str);
int			error_double(int nbr, t_node *a);

//	/rules		////////////////////////////////////////////////////////////////
// 	/push.c		/
void		push(t_node **a_list, t_node **b_list);
void		pa(t_node **a_list, t_node **b_list, bool checker);
void		pb(t_node **a_list, t_node **b_list, bool checker);

// 	/reverse.c	/
void		reverse_rotate(t_node *a);
void		rra(t_node *a, bool checker);
void		rrb(t_node *b, bool checker);
void		rrr(t_node **a_list, t_node **b_list, bool checker);

// 	/rotate.c	/
void		rotate(t_node *a);
void		ra(t_node *a, bool checker);
void		rb(t_node *b, bool checker);
void		rr(t_node **a_list, t_node **b_list, bool checker);

// 	/swap.c		/
void		swap(t_node **a_list);
void		sa(t_node **a_list, bool checker);
void		sb(t_node **b_list, bool checker);
void		ss(t_node **a_list, t_node **b_list, bool checker);

//	/sort		////////////////////////////////////////////////////////////////
//	/cost2.c	/
int			set_target_a2b(t_node *a, t_node **b_list);
int			set_target_b2a(t_node *a, t_node **b_list);
int			set_r_cost(t_node *a);
int			set_rr_cost(t_node *a);

//	/cost.c		/
void		set_cost_a2b(t_node **a_list, t_node **b_list);
void		set_cost_b2a(t_node **a_list, t_node **b_list);
t_node		*set_node_cost(t_node *a, t_node **b_list);
int			set_total_cost(t_node *a);

//	/methods_a2b.c /
void		method_1_a2b(t_node *node, t_node **b_list, t_cost cost);
void		method_2_a2b(t_node *node, t_node **b_list, t_cost cost);
void		method_3_a2b(t_node *node, t_node **b_list, t_cost cost);
void		method_4_a2b(t_node *node, t_node **b_list, t_cost cost);

//	/methods_b2a.c /
void		method_1_b2a(t_node *node, t_node **b_list, t_cost cost);
void		method_2_b2a(t_node *node, t_node **b_list, t_cost cost);
void		method_3_b2a(t_node *node, t_node **b_list, t_cost cost);
void		method_4_b2a(t_node *node, t_node **b_list, t_cost cost);

//	/sorting.c	/
void		sorting(t_node **a_list, t_node **b_list);
void		sorting_a2b(t_node **a_list, t_node **b_list);
void		sorting_b2a(t_node **b_list, t_node **a_list);
void		methods(t_node *node, t_node **b_list, int method, bool theway);
void		small_sort(t_node **a_list);

//	/utils		////////////////////////////////////////////////////////////////
//	/utils.c	/
t_node		*node_finder(t_node *node, bool where);
int			node_count(t_node *node);
bool		is_rev_sorted(t_node *node);
bool		is_sorted(t_node *node);
long		ft_atol(const char *nptr);

//	/utils2.c	/
t_minmax	find_minmax(t_node *a);
t_node		*find_cheapest(t_node **list);

//	/utils3.c	/
t_node		*find_biggest(t_node **list);
t_node		*find_smallest(t_node **list);
t_node		*rotate_to_biggest(t_node **list);
t_node		*rotate_to_smallest(t_node **list);

#endif