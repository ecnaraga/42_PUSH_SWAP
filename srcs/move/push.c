/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:02:12 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 13:06:40 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_write_order(int write, char *order)
{
	if (write == 1)
		ft_printf("%s\n", order);
}

void	ft_set_cont_push_swap_first(t_cont_push_swap *cont, t_lst_two_push_swap *tmp2)
{
	if (cont->size > 1)
	{
		cont->first = tmp2;
		cont->first->prev = NULL;
	}
	else
	{
		cont->first = NULL;
		cont->last = NULL;
	}
}

int	ft_push_a(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write)
{
	t_lst_two_push_swap	*tmp1;
	t_lst_two_push_swap	*tmp2;

	if (!cont_b->first || cont_b->size == 0)
		return (0);
	ft_write_order(write, "pa");
	tmp1 = cont_a->first;
	tmp2 = cont_b->first->next;
	cont_a->first = cont_b->first;
	cont_a->first->next = tmp1;
	if (tmp1)
		tmp1->prev = cont_a->first;
	else
		cont_a->last = cont_a->first;
	ft_set_cont_push_swap_first(cont_b, tmp2);
	cont_b->size -= 1;
	cont_a->size += 1;
	return (1);
}

int	ft_push_b(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write)
{
	t_lst_two_push_swap	*tmp1;
	t_lst_two_push_swap	*tmp2;

	if (!cont_a->first || cont_a->size == 0)
		return (0);
	ft_write_order(write, "pb");
	tmp1 = cont_b->first;
	tmp2 = cont_a->first->next;
	cont_b->first = cont_a->first;
	cont_b->first->next = tmp1;
	if (tmp1)
		tmp1->prev = cont_b->first;
	else
		cont_b->last = cont_b->first;
	ft_set_cont_push_swap_first(cont_a, tmp2);
	cont_b->size += 1;
	cont_a->size -= 1;
	return (1);
}
