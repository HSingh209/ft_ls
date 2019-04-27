/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:58:39 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 14:58:41 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_print_hex_lft_algn(intmax_t num, t_wd_flg *fl, char l)
{
	int n_len;

	n_len = ft_unsigned_n_len(num, 16);
	if (num == 0 && fl->is_snp && !fl->prc)
	{
		while (fl->wd--)
			fl->len += write(1, " ", 1);
		return ;
	}
	if (fl->is_hash && num != 0)
		n_len += 2;
	if (fl->is_hash && l == 'x' && num != 0)
		fl->len += write(1, "0x", 2);
	else if (fl->is_hash && l == 'X' && num != 0)
		fl->len += write(1, "0X", 2);
	while (n_len++ < fl->prc)
		fl->len += write(1, "0", 1);
	fl->len += ft_uitoa_base(num, 16, l);
	while (fl->wd-- >= n_len)
		fl->len += write(1, " ", 1);
}

static void		ft_prefx(uintmax_t num, t_wd_flg *fl, char l)
{
	if (fl->is_hash && l == 'x' && num != 0)
		fl->len += write(1, "0x", 2);
	else if (fl->is_hash && l == 'X' && num != 0)
		fl->len += write(1, "0X", 2);
}

static void		ft_print_hex_right_aln(uintmax_t num, t_wd_flg *fl, char l)
{
	int n_len;

	n_len = ft_unsigned_n_len(num, 16);
	if (num == 0 && fl->is_snp && !fl->prc)
	{
		while (fl->wd--)
			fl->len += write(1, " ", 1);
		return ;
	}
	if (fl->is_hash && num != 0)
		n_len += 2;
	if (fl->is_hash && fl->is_zero)
		ft_prefx(num, fl, l);
	ft_padding_ou(n_len, fl);
	while (n_len++ < fl->prc)
		fl->len += write(1, "0", 1);
	if (fl->is_hash && !fl->is_zero)
		ft_prefx(num, fl, l);
	fl->len += ft_uitoa_base(num, 16, l);
}

void			ft_print_hexi(char xc, t_wd_flg *fl, va_list typ)
{
	uintmax_t num;

	if (!fl->l_flag && !fl->ll_flag && !fl->h_flag && !fl->hh_flag)
		num = va_arg(typ, unsigned int);
	else if (fl->hh_flag)
		num = (unsigned char)va_arg(typ, unsigned int);
	else if (fl->h_flag)
		num = (unsigned short)va_arg(typ, unsigned int);
	else if (fl->ll_flag)
		num = va_arg(typ, unsigned long long);
	else if (fl->l_flag)
		num = va_arg(typ, unsigned long);
	if (fl->lft_algn)
		ft_print_hex_lft_algn(num, fl, xc);
	else
		ft_print_hex_right_aln(num, fl, xc);
}
