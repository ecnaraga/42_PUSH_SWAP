/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:28:21 by galambey          #+#    #+#             */
/*   Updated: 2023/07/06 15:54:40 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_reverse_rotate(t_cont_push_swap *cont, char *order)
{
	t_lst_two_push_swap	*tmp1;
	t_lst_two_push_swap	*tmp2;

	if (!cont->first || cont->size == 1)
		return (0);
	if (order)
		ft_printf("%s\n", order);
	tmp1 = cont->first;
	tmp2 = cont->last;
	cont->last = cont->last->prev;
	cont->last->next = NULL;
	cont->first->prev = tmp2;
	cont->first = cont->first->prev;
	cont->first->next = tmp1;
	cont->first->prev = NULL;
	return (1);
}

int	ft_reverse_rotate_r(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write)
{
	if (cont_a->first)
		ft_reverse_rotate(cont_a, NULL);
	if (cont_b->first)
		ft_reverse_rotate(cont_b, NULL);
	if (write == 1)
		ft_printf("rrr\n");
	return (1);
}
