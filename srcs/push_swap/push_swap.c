/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:08:40 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 12:29:26 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_cont	*cont_a;
	int		i;

	i = 0;
	if (ac < 2)
		exit(0);
	cont_a = malloc(sizeof(t_cont));
	if (!cont_a)
		ft_error(cont_a, NULL, NULL);
	cont_a->first = NULL;
	if (ac > 2)
		cont_a = ft_make_cont1(ac, av, cont_a, 0);
	else
	{
		while (av[1][0] && av[1][i] == ' ')
			i++;
		if (av[1][0] == '\0' || av[1][i] == '\0')
			ft_error(cont_a, NULL, NULL);
		cont_a = ft_make_cont2(av, cont_a, 0);
	}
	ft_set_index(cont_a);
	ft_sort_list(cont_a);
	return (0);
}
