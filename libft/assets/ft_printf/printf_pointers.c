/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:15:02 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:42:12 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_print_poiter_left_algn(intmax_t num, t_wd_flg *fl)
{
	int		n_len;

	n_len = ft_unsigned_n_len(num, 16) + 2;
	fl->len += write(1, "0x", 2);
	if (num == 0 && fl->is_snp && !fl->prc)
		return ;
	while ((n_len - 2) < fl->prc)
	{
		fl->len += write(1, "0", 1);
		n_len++;
	}
	fl->len += ft_uitoa_base(num, 16, 0);
	while (fl->wd-- > n_len)
		fl->len += write(1, " ", 1);
}

static void		ft_print_pointer_right(uintmax_t num, t_wd_flg *fl)
{
	int		n_len;

	n_len = ft_unsigned_n_len(num, 16) + 2;
	while (fl->wd-- > n_len)
		fl->len += write(1, " ", 1);
	fl->len += write(1, "0x", 2);
	if (num == 0 && fl->is_snp && !fl->prc)
		return ;
	while ((n_len - 2) < fl->prc)
	{
		fl->len += write(1, "0", 1);
		n_len++;
	}
	fl->len += ft_uitoa_base(num, 16, 0);
}

void			ft_print_pa(t_wd_flg *fl, va_list typ)
{
	uintmax_t pa;

	pa = (long long)va_arg(typ, void *);
	if (fl->lft_algn)
		ft_print_poiter_left_algn(pa, fl);
	else
		ft_print_pointer_right(pa, fl);
}
