/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:28:26 by garance           #+#    #+#             */
/*   Updated: 2023/07/07 12:53:39 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst_two	*get_min_five(t_cont *cont, int size)
{
	int			i;
	int			j;
	t_lst_two	*tmp;
	t_lst_two	*min;

	i = 0;
	j = 0;
	min = NULL;
	tmp = cont->first;
	while (cont->first)
	{
		if (!min || cont->first->index < min->index)
		{
			min = cont->first;
			j = i;
		}
		i++;
		cont->first = cont->first->next;
	}
	cont->first = tmp;
	min->way = (j <= (size + 1) / 2) * (1);
	return (min);
}

void	sort_three(t_cont *cont, int *cost)
{
	if (cont->first->next->data > cont->first->data
		&& cont->first->next->data > cont->last->data)
		*cost += ft_reverse_rotate(cont, "rra");
	if (cont->first->data > cont->first->next->data
		&& cont->first->data > cont->last->data)
		*cost += ft_rotate(cont, "ra");
	if ((cont->first->data > cont->first->next->data
			&& cont->first->data < cont->last->data)
		|| (cont->first->data < cont->first->next->data
			&& cont->first->data > cont->last->data))
		*cost += ft_swap(cont, "sa");
}

void	ft_sort_five(t_cont *cont_a, t_cont *cont_b, int size, int *cost)
{
	t_lst_two	*min;
	int			i;

	i = 0;
	while (size-- > 3)
	{
		min = get_min_five(cont_a, size);
		while (cont_a->first->index != min->index)
		{
			if (min->way == 1 && size == 4 && cont_a->first->index == min->index
				+ 1 && cont_a->first->next->index == min->index)
				*cost += ft_swap(cont_a, "sa");
			else if (min->way == 1)
				*cost += ft_rotate(cont_a, "ra");
			else
				*cost += ft_reverse_rotate(cont_a, "rra");
		}
		*cost += ft_push_b(cont_a, cont_b, 1);
		i++;
	}
	sort_three(cont_a, cost);
	while (--i >= 0)
		*cost += ft_push_a(cont_a, cont_b, 1);
}
