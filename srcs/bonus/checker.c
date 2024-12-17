/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:29:21 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 12:53:53 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/checker.h"

int	ft_do_line(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		ft_push_a(cont_a, cont_b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push_b(cont_a, cont_b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(cont_a, NULL);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(cont_b, NULL);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rotate_r(cont_a, cont_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse_rotate(cont_a, NULL);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse_rotate(cont_b, NULL);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_reverse_rotate_r(cont_a, cont_b, 0);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(cont_a, NULL);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(cont_b, NULL);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_swap_s(cont_a, cont_b, 0);
	else
		return (1);
	return (0);
}

void	ft_final_check(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b)
{
	t_lst_two_push_swap	*tmp;
	int			i;

	i = 0;
	if (cont_a->first)
	{
		tmp = cont_a->first;
		while (cont_a->first->next)
		{
			if (cont_a->first->next->data < cont_a->first->data)
			{
				write(1, "KO\n", 3);
				i = 1;
				break ;
			}
			cont_a->first = cont_a->first->next;
		}
		cont_a->first = tmp;
		if (i == 0)
			write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
	ft_free_ok(cont_a, cont_b);
}

void	checker(t_cont_push_swap *cont_a)
{
	char	*line;
	int		check;
	t_cont_push_swap	*cont_b;

	check = 0;
	cont_b = malloc(sizeof(t_cont_push_swap));
	if (!cont_b)
		ft_error(cont_a, NULL, NULL);
	cont_b->first = NULL;
	cont_b->last = NULL;
	cont_b->size = 0;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		check = ft_do_line(cont_a, cont_b, line);
		if (check == 1)
		{
			free(line);
			ft_error(cont_a, cont_b, NULL);
		}
		free(line);
	}
	ft_final_check(cont_a, cont_b);
}

int	main(int ac, char **av)
{
	t_cont_push_swap	*cont_a;
	int		i;

	i = 0;
	if (ac < 2)
		exit(0);
	cont_a = malloc(sizeof(t_cont_push_swap));
	if (!cont_a)
		ft_error(cont_a, NULL, NULL);
	cont_a->first = NULL;
	if (ac > 2)
		cont_a = ft_make_cont1(ac, av, cont_a, 1);
	else
	{
		while (av[1][0] && av[1][i] == ' ')
			i++;
		if (av[1][0] == '\0' || av[1][i] == '\0')
			ft_error(cont_a, NULL, NULL);
		cont_a = ft_make_cont2(av, cont_a, 1);
	}
	checker(cont_a);
	return (0);
}
