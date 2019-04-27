/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:53:31 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:25:34 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

int		ft_signed_num_len(intmax_t value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < -9223372036854775807)
		return (20);
	if (value < 0)
	{
		i++;
		value *= -1;
	}
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

int		ft_unsigned_n_len(intmax_t value, int base)
{
	int	i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}
