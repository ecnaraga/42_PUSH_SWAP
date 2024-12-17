/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:22:28 by galambey          #+#    #+#             */
/*   Updated: 2023/07/04 21:22:39 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_lst_two_push_swap	*ft_get_next_min(t_cont_push_swap *cont)
{
	t_lst_two_push_swap	*min;

	min = NULL;
	while (cont->first)
	{
		if (cont->first->index == -1 && (!min || min->data > cont->first->data))
			min = cont->first;
		cont->first = cont->first->next;
	}
	return (min);
}

void	ft_set_index(t_cont_push_swap *cont)
{
	t_lst_two_push_swap	*tmp;
	int			i;

	i = 0;
	tmp = cont->first;
	while (1)
	{
		cont->first = ft_get_next_min(cont);
		if (!cont->first)
			break ;
		cont->first->index = i;
		cont->first = tmp;
		i++;
	}
	cont->first = tmp;
}
