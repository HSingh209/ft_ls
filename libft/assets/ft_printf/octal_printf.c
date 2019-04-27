/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:15:14 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:44:35 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_printf_octal_left(intmax_t num, t_wd_flg *fl)
{
	int		n_len;

	n_len = ft_unsigned_n_len(num, 8);
	if (num == 0 && fl->is_snp && !fl->prc)
	{
		while (fl->wd)
		{
			fl->len += write(1, " ", 1);
			fl->wd--;
		}
		if (!fl->is_hash)
			return ;
	}
	if (fl->is_hash && num != 0)
	{
		fl->len += write(1, "0", 1);
		n_len++;
	}
	while (n_len++ < fl->prc)
		fl->len += write(1, "0", 1);
	fl->len += ft_uitoa_base(num, 8, 0);
	while (fl->wd-- >= n_len)
		fl->len += write(1, " ", 1);
}

void			ft_padding_ou(int n_len, t_wd_flg *fl)
{
	fl->prc = (fl->prc < n_len) ? n_len : fl->prc;
	if (!fl->is_snp)
		while (fl->wd-- > n_len)
		{
			if (fl->is_zero)
				fl->len += write(1, "0", 1);
			else
				fl->len += write(1, " ", 1);
		}
	else
	{
		if (fl->show_sign || fl->is_zero)
			fl->wd--;
		while (fl->wd-- > n_len)
		{
			if (fl->is_zero)
				fl->len += write(1, "0", 1);
			else
				fl->len += write(1, " ", 1);
		}
	}
}

static void		ft_printf_octal_right(uintmax_t num, t_wd_flg *fl)
{
	int n_len;

	n_len = ft_unsigned_n_len(num, 8);
	if (num == 0 && fl->is_snp && !fl->prc)
	{
		if (fl->is_hash)
			fl->len += write(1, "0", 1);
		while (fl->wd)
		{
			fl->len += write(1, " ", 1);
			fl->wd--;
		}
		return ;
	}
	if (fl->is_hash && num != 0)
		n_len++;
	ft_padding_ou(n_len, fl);
	while (n_len++ < fl->prc)
		fl->len += write(1, "0", 1);
	if (fl->is_hash && num != 0)
		fl->len += write(1, "0", 1);
	fl->len += ft_uitoa_base(num, 8, 0);
}

void			ft_print_oct(t_wd_flg *fl, va_list typ)
{
	uintmax_t num;

	if (!fl->l_flag && !fl->ll_flag && !fl->h_flag && !fl->hh_flag)
		num = va_arg(typ, unsigned int);
	else if (fl->hh_flag)
		num = (unsigned char)va_arg(typ, unsigned int);
	else if (fl->h_flag)
		num = (unsigned short)va_arg(typ, unsigned int);
	else if (fl->l_flag)
		num = va_arg(typ, long);
	else if (fl->ll_flag)
		num = va_arg(typ, long long);
	if (fl->lft_algn)
		ft_printf_octal_left(num, fl);
	else
		ft_printf_octal_right(num, fl);
}
