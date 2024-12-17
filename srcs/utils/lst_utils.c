/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:07:46 by galambey          #+#    #+#             */
/*   Updated: 2023/07/05 15:01:59 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst_two	*lst_two_addnew_pushswap(long int data)
{
	t_lst_two	*new;

	new = (t_lst_two *)malloc(sizeof(t_lst_two));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->data = data;
	new->index = -1;
	new->cost = 0;
	new->way = 0;
	new->next = NULL;
	return (new);
}

void	lst_two_addback_pushswap(t_cont *cont, t_lst_two *new)
{
	if (cont->first->next == NULL)
	{
		new->prev = cont->first;
		cont->first->next = new;
	}
	else
	{
		new->prev = cont->last;
		cont->last->next = new;
	}
	cont->last = new;
}

int	lst_two_size_pushswap(t_cont *cont)
{
	t_lst_two	*lst;
	int			count;

	lst = cont->first;
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
