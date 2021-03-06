/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversion_printf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:42:45 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 14:43:48 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static long long int	ft_pow(int nb, int power)
{
	int			cpt;
	long long	value;

	cpt = 1;
	value = nb;
	if (power > 0)
		while (cpt++ < power)
			value = value * nb;
	else
	{
		if (power == 0)
			value = 1;
		else
			value = 0;
	}
	return (value);
}

static long				ft_round(double n, int precision)
{
	long long	tmp;

	tmp = n * ft_pow(10, precision + 1);
	if (tmp % 10 >= 5)
		tmp = tmp / 10 + 1;
	else if (tmp % 10 <= -5)
		tmp = tmp / 10 - 1;
	else
		tmp /= 10;
	return (tmp);
}

char					*ft_ldtoa(double n, int precision)
{
	char		*str;
	long long	tmp;
	long long	t;
	int			length;

	if (!precision)
		return (ft_itoa((int)n));
	tmp = ft_round(n, precision);
	t = (tmp < 0) ? -tmp : tmp;
	length = (n < 0 ? 3 : 2);
	while (tmp /= 10)
		++length;
	(n < 1 && n > -1) ? length = 3 + precision : 0;
	(n >= 0 && n < 1) ? length = 2 + precision : 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * length + 1)))
		return (NULL);
	str[length] = '\0';
	while (length > 0)
	{
		str[length - 1] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
		length--;
	}
	(n < 0) ? str[0] = '-' : 0;
	return (str);
}
