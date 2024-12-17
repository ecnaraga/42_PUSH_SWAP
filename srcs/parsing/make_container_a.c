/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_container_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:09:04 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 11:47:55 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_input(t_cont *cont, int bonus)
{
	t_lst_two	*lst;
	t_lst_two	*lst_next;
	int			i;

	lst = cont->first;
	i = 0;
	while (lst)
	{
		lst_next = lst->next;
		if (lst->next && lst_next->data < lst->data)
			i++;
		while (lst_next)
		{
			if (lst_next->data == lst->data)
				ft_error(cont, NULL, NULL);
			lst_next = lst_next->next;
		}
		if (lst->data == 3000000000)
			ft_error(cont, NULL, NULL);
		lst = lst->next;
	}
	if (i == 0 && bonus == 1)
		ft_printf("OK\n");
	if (i == 0)
		ft_free_ok(cont, NULL);
}

t_cont	*ft_make_cont1(int ac, char **av, t_cont *cont, int bonus)
{
	int			i;
	long int	nb;
	t_lst_two	*new;

	i = 1;
	nb = ft_atoi_digit(av[i]);
	cont->first = lst_two_addnew_pushswap(nb);
	if (!cont->first)
		ft_error(cont, NULL, NULL);
	while (++i < ac)
	{
		nb = ft_atoi_digit(av[i]);
		new = lst_two_addnew_pushswap(nb);
		if (!new)
			ft_error(cont, NULL, NULL);
		lst_two_addback_pushswap(cont, new);
	}
	ft_check_input(cont, bonus);
	cont->size = lst_two_size_pushswap(cont);
	return (cont);
}

t_cont	*ft_make_cont2(char **av, t_cont *cont, int bonus)
{
	int			i;
	long int	nb;
	t_lst_two	*new;
	char		**array;

	array = ft_split(av[1], ' ');
	if (!array)
		ft_error(cont, NULL, NULL);
	i = 0;
	nb = ft_atoi_digit(array[i]);
	cont->first = lst_two_addnew_pushswap(nb);
	if (!cont->first)
		ft_error(cont, NULL, array);
	while (array[++i])
	{
		nb = ft_atoi_digit(array[i]);
		new = lst_two_addnew_pushswap(nb);
		if (!new)
			ft_error(cont, NULL, array);
		lst_two_addback_pushswap(cont, new);
	}
	ft_free_array(array);
	ft_check_input(cont, bonus);
	cont->size = lst_two_size_pushswap(cont);
	return (cont);
}
