/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_ints_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:58:17 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:32:50 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_print_unsigned_left_algn(intmax_t num, t_wd_flg *fl)
{
	int n_len;

	n_len = ft_unsigned_n_len(num, 10);
	if (num == 0 && fl->is_snp && !fl->prc)
	{
		while (fl->wd--)
			fl->len += write(1, " ", 1);
		return ;
	}
	while (n_len++ < fl->prc)
		fl->len += write(1, "0", 1);
	fl->len += ft_uitoa_base(num, 10, 0);
	while (fl->wd-- >= n_len)
		fl->len += write(1, " ", 1);
}

static void		ft_print_unsigned_right_algn(uintmax_t num, t_wd_flg *fl)
{
	int		n_len;

	n_len = ft_unsigned_n_len(num, 10);
	if (num == 0 && fl->is_snp && !fl->prc)
	{
		while (fl->wd--)
			fl->len += write(1, " ", 1);
		return ;
	}
	ft_padding_ou(n_len, fl);
	while (n_len++ < fl->prc)
		fl->len += write(1, "0", 1);
	fl->len += ft_uitoa_base(num, 10, 0);
}

void			ft_print_uns_nbr(t_wd_flg *fl, va_list typ)
{
	uintmax_t nbr;

	if (!fl->l_flag && !fl->ll_flag && !fl->h_flag && !fl->hh_flag)
		nbr = va_arg(typ, unsigned int);
	else if (fl->hh_flag)
		nbr = (unsigned char)va_arg(typ, unsigned int);
	else if (fl->h_flag)
		nbr = (unsigned short)va_arg(typ, unsigned int);
	else if (fl->ll_flag)
		nbr = va_arg(typ, unsigned long long);
	else if (fl->l_flag)
		nbr = va_arg(typ, unsigned long);
	if (fl->lft_algn)
		ft_print_unsigned_left_algn(nbr, fl);
	else
		ft_print_unsigned_right_algn(nbr, fl);
}
