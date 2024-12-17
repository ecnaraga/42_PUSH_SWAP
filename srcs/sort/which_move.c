/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:38:44 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 13:05:19 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_set_cost_a(t_lst_two_push_swap *pile_a, int size, int i)
{
	if (i <= size / 2)
	{
		pile_a->cost = i;
		pile_a->way = 1;
	}
	else
	{
		pile_a->cost = size - i;
		pile_a->way = -1;
	}
}

t_lst_two_push_swap	*ft_maj_pile_a(t_lst_two_push_swap *pile_b, t_cont_push_swap *cont_a)
{
	t_lst_two_push_swap	*tmp;
	t_lst_two_push_swap	*maj;
	int			i;

	i = 0;
	tmp = cont_a->first;
	maj = NULL;
	while (cont_a->first)
	{
		ft_set_cost_a(cont_a->first, cont_a->size, i);
		if ((!maj && cont_a->first->index > pile_b->index) || (maj
				&& maj->index > cont_a->first->index
				&& cont_a->first->index > pile_b->index))
			maj = cont_a->first;
		i++;
		cont_a->first = cont_a->first->next;
	}
	cont_a->first = tmp;
	return (maj);
}

void	ft_set_cost_b(t_lst_two_push_swap *pile_b, t_lst_two_push_swap *maj, int size, int i)
{
	if (i <= size / 2)
	{
		pile_b->cost = 1 + i + maj->cost;
		pile_b->way = 1 * maj->way;
	}
	else
	{
		pile_b->cost = 1 + size - i + maj->cost;
		pile_b->way = 2 * maj->way;
	}
}

t_lst_two_push_swap	*ft_look_best_move(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b)
{
	t_lst_two_push_swap	*tmp;
	t_lst_two_push_swap	*best;
	t_lst_two_push_swap	*maj;
	int			i;

	i = 0;
	tmp = cont_b->first;
	best = NULL;
	while (cont_b->first)
	{
		maj = ft_maj_pile_a(cont_b->first, cont_a);
		ft_set_cost_b(cont_b->first, maj, cont_b->size, i);
		if (!best || best->cost > cont_b->first->cost)
			best = cont_b->first;
		i++;
		cont_b->first = cont_b->first->next;
	}
	cont_b->first = tmp;
	return (best);
}
