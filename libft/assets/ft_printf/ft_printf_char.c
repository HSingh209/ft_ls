/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:55:29 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 14:56:31 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_print_char_left_align(unsigned char c, t_wd_flg *fl)
{
	fl->len += write(1, &c, 1);
	while (fl->wd > 1)
	{
		fl->len += write(1, " ", 1);
		fl->wd--;
	}
}

static void		ft_print_char_right_align(unsigned char c, t_wd_flg *fl)
{
	while (fl->wd > 1)
	{
		if (fl->is_zero)
			fl->len += write(1, "0", 1);
		else
			fl->len += write(1, " ", 1);
		fl->wd--;
	}
	fl->len += write(1, &c, 1);
}

void			ft_print_ch(char c, t_wd_flg *fl, va_list typ)
{
	unsigned char ch;

	if (c == 'c')
	{
		ch = (unsigned char)va_arg(typ, int);
		if (fl->lft_algn)
			ft_print_char_left_align(ch, fl);
		else
			ft_print_char_right_align(ch, fl);
	}
}
