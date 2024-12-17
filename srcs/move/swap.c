/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:06:57 by galambey          #+#    #+#             */
/*   Updated: 2023/07/06 15:52:28 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_swap(t_cont_push_swap *cont, char *order)
{
	t_lst_two_push_swap	*tmp1;
	t_lst_two_push_swap	*tmp2;

	if (!cont->first || cont->size == 1)
		return (0);
	if (order)
		ft_printf("%s\n", order);
	tmp1 = cont->first;
	tmp1->prev = cont->first->next;
	tmp2 = cont->first->next;
	tmp1->next = tmp2->next;
	tmp2->prev = NULL;
	tmp2->next = tmp1;
	cont->first = tmp2;
	if (tmp1->next == NULL)
		cont->last = tmp1;
	else if (cont->last->prev == tmp2)
		cont->last->prev = tmp1;
	return (1);
}

int	ft_swap_s(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write)
{
	if (cont_a->first)
		ft_swap(cont_a, NULL);
	if (cont_b->first)
		ft_swap(cont_b, NULL);
	if (write == 1)
		ft_printf("ss\n");
	return (1);
}
