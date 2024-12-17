/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:26:37 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 13:05:51 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_rotate(t_cont_push_swap *cont, char *order)
{
	t_lst_two_push_swap	*tmp1;
	t_lst_two_push_swap	*tmp2;

	if (!cont->first || cont->size == 1)
		return (0);
	if (order)
		ft_printf("%s\n", order);
	tmp1 = cont->first;
	tmp2 = cont->last;
	cont->first = cont->first->next;
	cont->first->prev = NULL;
	cont->last->next = tmp1;
	cont->last = cont->last->next;
	cont->last->prev = tmp2;
	cont->last->next = NULL;
	return (1);
}

int	ft_rotate_r(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write)
{
	if (cont_a->first)
		ft_rotate(cont_a, NULL);
	if (cont_b->first)
		ft_rotate(cont_b, NULL);
	if (write == 1)
		ft_printf("rr\n");
	return (1);
}
