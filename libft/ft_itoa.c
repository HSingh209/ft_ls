/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:02:23 by harssing          #+#    #+#             */
/*   Updated: 2018/10/27 20:17:23 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		n_len;
	int		neg_n;
	int		temp_n;
	char	*itoa;

	neg_n = 0;
	if (n < 0)
		neg_n = 1;
	temp_n = n;
	n_len = 1;
	while (temp_n /= 10)
		n_len++;
	if (!(itoa = ft_strnew((n_len + neg_n))))
		return (itoa);
	if (itoa == NULL)
		return (NULL);
	if (neg_n)
		itoa[0] = '-';
	while (n_len--)
	{
		itoa[n_len + neg_n] = (neg_n ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (itoa);
}
