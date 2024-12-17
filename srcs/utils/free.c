/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:37:57 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 12:39:34 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	*ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

void	*ft_free_lst(t_lst_two_push_swap *lst)
{
	t_lst_two_push_swap	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (NULL);
}

void	ft_error(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, char **array)
{
	ft_putstr_fd("Error\n", 2);
	if (cont_a)
	{
		if (cont_a->first)
			ft_free_lst(cont_a->first);
		free(cont_a);
	}
	if (cont_b)
		free(cont_b);
	if (array)
		ft_free_array(array);
	exit(1);
}

void	ft_free_ok(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b)
{
	if (cont_a->first)
		ft_free_lst(cont_a->first);
	free(cont_a);
	if (cont_b)
	{
		if (cont_b->first)
			ft_free_lst(cont_b->first);
		free(cont_b);
	}
	exit(0);
}
