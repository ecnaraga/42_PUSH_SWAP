/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:22:30 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 12:55:58 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	first_push_b(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int max, int size)
{
	int	cost;

	cost = 0;
	while (cont_a->size > 5 && ((cont_b->size < max && max < size - 1)
			|| (cont_b->size + 5 <= max && max == size - 1)))
	{
		if (cont_a->first->index < max)
			cost = cost + ft_push_b(cont_a, cont_b, 1);
		else
			cost = cost + ft_rotate(cont_a, "ra");
	}
	return (cost);
}

void	ft_sort_by_rotate(t_cont_push_swap *cont_a, int *cost, int min)
{
	t_lst_two_push_swap	*lst;
	int			i;

	lst = cont_a->first;
	i = 0;
	while (lst)
	{
		i++;
		if (lst->index == min)
			break ;
		lst = lst->next;
	}
	if (i > lst_two_size_pushswap(cont_a) / 2)
		while (cont_a->first->index > cont_a->last->index)
			*cost += ft_reverse_rotate(cont_a, "rra");
	else
		while (cont_a->first->index > cont_a->last->index)
			*cost += ft_rotate(cont_a, "ra");
}

void	ft_final_sort(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int *cost)
{
	t_lst_two_push_swap	*best;
	t_lst_two_push_swap	*maj;

	while (cont_b->size >= 1)
	{
		best = ft_look_best_move(cont_a, cont_b);
		maj = ft_maj_pile_a(best, cont_a);
		while (best->way == 1 && cont_b->first != best && cont_a->first != maj)
			*cost += ft_rotate_r(cont_a, cont_b, 1);
		while (best->way == -2 && cont_b->first != best && cont_a->first != maj)
			*cost += ft_reverse_rotate_r(cont_a, cont_b, 1);
		while ((best->way == 1 || best->way == -1) && cont_b->first != best)
			*cost += ft_rotate(cont_b, "rb");
		while ((best->way == 2 || best->way == -2) && cont_b->first != best)
			*cost += ft_reverse_rotate(cont_b, "rrb");
		while ((best->way == 1 || best->way == 2) && cont_a->first != maj)
			*cost += ft_rotate(cont_a, "ra");
		while ((best->way == -1 || best->way == -2) && cont_a->first != maj)
			*cost += ft_reverse_rotate(cont_a, "rra");
		*cost += ft_push_a(cont_a, cont_b, 1);
	}
	ft_sort_by_rotate(cont_a, cost, 0);
}

void	ft_sort_six_or_plus(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int *cost)
{
	int	size;
	int	max;
	int	i;

	i = 0;
	size = cont_a->size;
	while (i < 2)
	{
		max = (i == 1) * (size - 1) + (i == 0) * (size / 2) * (i + 1);
		*cost = *cost + first_push_b(cont_a, cont_b, max, size);
		i++;
	}
	ft_sort_five(cont_a, cont_b, 5, cost);
	ft_final_sort(cont_a, cont_b, cost);
}

void	ft_sort_list(t_cont_push_swap *cont_a)
{
	t_cont_push_swap	*cont_b;
	int		cost;

	cost = 0;
	cont_b = malloc(sizeof(t_cont_push_swap));
	if (!cont_b)
		ft_error(cont_a, NULL, NULL);
	cont_b->first = NULL;
	cont_b->last = NULL;
	cont_b->size = 0;
	if (cont_a->size == 2)
	{
		if (cont_a->first->index > cont_a->first->next->index)
			cost += ft_swap(cont_a, "sa");
	}
	else if (cont_a->size <= 5)
		ft_sort_five(cont_a, cont_b, cont_a->size, &cost);
	if (cont_a->size > 5)
		ft_sort_six_or_plus(cont_a, cont_b, &cost);
	ft_free_ok(cont_a, cont_b);
}
