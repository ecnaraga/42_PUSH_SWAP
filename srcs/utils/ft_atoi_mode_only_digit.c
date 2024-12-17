/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mode_only_digit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:44:03 by garance           #+#    #+#             */
/*   Updated: 2023/07/05 14:59:03 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_signe(char c, int *s, int *i)
{
	if (c == '-')
	{
		*s = -1;
		*i += 1;
	}
}

long int	ft_atoi_digit(char *str)
{
	int			i;
	long int	n;
	int			count;
	int			s;

	n = 0;
	i = 0;
	count = 0;
	s = 1;
	if (!str)
		return (3000000000);
	ft_signe(str[0], &s, &i);
	if (!str[i] || str[i] < '0' || str[i] > '9')
		return (3000000000);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i++] - 48;
		count++;
	}
	if (str[i] || n * s > 2147483647 || n * s < -2147483648 || count > 10)
		return (3000000000);
	return (n * s);
}
