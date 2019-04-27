/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:39:08 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 14:42:19 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

int			ft_itoa_base(intmax_t val, int base)
{
	int			len;
	intmax_t	temp_num;
	char		*rdx;
	char		*res;

	rdx = "0123456789ABCDEF";
	len = 1;
	temp_num = val;
	if (val < -9223372036854775807)
		return (write(1, "9223372036854775808", 19));
	while (temp_num /= base)
		len++;
	if ((res = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	res[len] = '\0';
	while (len-- > 0)
	{
		res[len] = rdx[val % base];
		val /= base;
	}
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}

int			ft_uitoa_base(uintmax_t val, int base, char x)
{
	int			len;
	uintmax_t	temp_num;
	char		*rdxa;
	char		*rdxb;
	char		*res;

	rdxa = "0123456789abcdef";
	rdxb = "0123456789ABCDEF";
	len = 1;
	temp_num = val;
	while (temp_num /= base)
		len++;
	if ((res = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	res[len] = '\0';
	while (len-- > 0)
	{
		res[len] = (x == 'X') ? rdxb[val % base] : rdxa[val % base];
		val /= base;
	}
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}
