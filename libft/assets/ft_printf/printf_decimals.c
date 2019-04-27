/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_decimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:58:56 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:38:11 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static int		ft_deci_l_pre(intmax_t nbr, int n, t_wd_flg *f)
{
	if (nbr == 0 && f->is_snp && !f->prc)
	{
		if (f->show_sign && f->wd)
			f->wd--;
		if (f->show_sign)
			f->len += write(1, "+", 1);
		while (f->wd)
		{
			f->len += write(1, " ", 1);
			f->wd--;
		}
		return (1);
	}
	if (f->is_space && n == 0)
	{
		f->len += write(1, " ", 1);
		f->wd--;
	}
	return (0);
}

static void		ft_print_dec_left(intmax_t nbr, t_wd_flg *f)
{
	int nbrlen;
	int n;

	nbrlen = ft_signed_num_len(nbr, 10);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (ft_deci_l_pre(nbr, n, f))
		return ;
	if (f->show_sign && n == 0)
	{
		f->len += write(1, "+", 1);
		nbrlen++;
		f->prc++;
	}
	if (n == 1)
	{
		f->len += write(1, "-", 1);
		nbrlen--;
		f->wd--;
	}
	while (nbrlen++ < f->prc)
		f->len += write(1, "0", 1);
	f->len += ft_itoa_base(nbr, 10);
	ft_pad_left_align(nbrlen, f);
}

static int		ft_deci_right_pre(intmax_t num, int neg, t_wd_flg *fl)
{
	if (num == 0 && fl->is_snp && !fl->prc)
	{
		if (fl->show_sign && fl->wd)
			fl->wd--;
		while (fl->wd)
		{
			fl->len += write(1, " ", 1);
			fl->wd--;
		}
		if (fl->show_sign)
			fl->len += write(1, "+", 1);
		return (1);
	}
	if (fl->is_space && !neg && !fl->wd)
		fl->len += write(1, " ", 1);
	if (fl->show_sign && fl->is_zero && !neg)
		fl->len += write(1, "+", 1);
	if (neg && fl->is_zero)
		fl->len += write(1, "-", 1);
	return (0);
}

static void		ft_print_dec_right(intmax_t num, t_wd_flg *fl)
{
	int	n_len;
	int	neg;

	n_len = ft_signed_num_len(num, 10);
	neg = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	if (ft_deci_right_pre(num, neg, fl))
		return ;
	if (fl->show_sign && !neg && fl->wd && !fl->is_snp)
		n_len++;
	ft_right_alg_pad(n_len, neg, fl);
	if (!fl->is_zero && fl->show_sign && !neg)
		fl->len += write(1, "+", 1);
	else if (!fl->is_zero && neg)
	{
		fl->len += write(1, "-", 1);
		n_len--;
	}
	fl->prc = (fl->wd > fl->prc) ? fl->wd : fl->prc;
	(neg && !fl->is_snp) ? fl->prc-- : 0;
	while (n_len++ < fl->prc)
		fl->len += write(1, "0", 1);
	fl->len += ft_itoa_base(num, 10);
}

void			ft_print_id(char c, t_wd_flg *fl, va_list typ)
{
	intmax_t num;

	if (c == 'd' || c == 'i')
	{
		if (!fl->l_flag && !fl->ll_flag && !fl->h_flag && !fl->hh_flag)
			num = va_arg(typ, int);
		else if (fl->hh_flag)
			num = (signed char)va_arg(typ, int);
		else if (fl->h_flag)
			num = (short)va_arg(typ, int);
		else if (fl->l_flag)
			num = va_arg(typ, long);
		else if (fl->ll_flag)
			num = va_arg(typ, long long);
		if (fl->lft_algn)
			ft_print_dec_left(num, fl);
		else
			ft_print_dec_right(num, fl);
	}
}
