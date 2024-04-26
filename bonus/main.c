/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:35:37 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/25 14:49:11 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	bool		split;

	a = NULL;
	b = NULL;
	split = 0;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (2 == argc)
	{
		argv = ft_split(argv[1], ' ');
		split = 1;
	}
	stack_init(&a, argv, split);
	checker(a, b);
	if (!is_valid(&a, &b))
		return (ft_putstr_fd("KO\n", 1),
			error_free(a, b, argv, split), 0);
	return (ft_putstr_fd("OK\n", 1),
		error_free(a, b, argv, split), 0);
}

void	checker(t_node *a, t_node *b)
{
	char		*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || !*line)
			break ;
		sort_check(line, &a, &b);
		free(line);
	}
}

void	sort_check(char *line, t_node **a, t_node **b)
{
	if (!ft_strncmp(line, "pa\n", 3))
		return (pa(a, b, CHECK));
	if (!ft_strncmp(line, "pb\n", 3))
		return (pb(a, b, CHECK));
	if (!ft_strncmp(line, "sa\n", 3))
		return (sa(a, CHECK));
	if (!ft_strncmp(line, "sb\n", 3))
		return (sb(b, CHECK));
	if (!ft_strncmp(line, "ss\n", 3))
		return (ss(a, b, CHECK));
	if (!ft_strncmp(line, "ra\n", 3))
		return (ra(*a, CHECK));
	if (!ft_strncmp(line, "rb\n", 3))
		return (rb(*b, CHECK));
	if (!ft_strncmp(line, "rr\n", 3))
		return (rr(a, b, CHECK));
	if (!ft_strncmp(line, "rra\n", 4))
		return (rra(*a, CHECK));
	if (!ft_strncmp(line, "rrb\n", 4))
		return (rrb(*b, CHECK));
	if (!ft_strncmp(line, "rrr\n", 4))
		return (rrr(a, b, CHECK));
	else
		return (ft_putstr_fd(line, 2));
}

bool	is_valid(t_node **a_list, t_node **b_list)
{
	if (is_sorted(*a_list)
		&& node_finder(*a_list, TOP)->data == find_minmax(*a_list).min
		&& !node_count(node_finder(*b_list, TOP)))
		return (1);
	return (0);
}
