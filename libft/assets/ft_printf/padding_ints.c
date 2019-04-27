/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:56:40 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:31:04 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

void		ft_pad_left_align(int n_len, t_wd_flg *f)
{
	while (f->wd >= n_len)
	{
		f->len += write(1, " ", 1);
		f->wd--;
	}
}

void		ft_right_alg_pad(int n_len, int neg, t_wd_flg *fl)
{
	if (fl->wd > fl->prc)
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
		if (fl->show_sign)
			fl->wd--;
		while (fl->wd-- > fl->prc)
		{
			if ((fl->is_zero && fl->wd != fl->prc) || neg)
				fl->len += write(1, "0", 1);
			else
				fl->len += write(1, " ", 1);
		}
	}
}
