/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:40:20 by harssing          #+#    #+#             */
/*   Updated: 2018/10/25 21:03:25 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		neg_n;

	i = 0;
	n = 0;
	neg_n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg_n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = n * 10;
		n += str[i++] - 48;
	}
	return (n * neg_n);
}
