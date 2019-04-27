/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent_sign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:54:01 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:27:24 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_print_perc_left_algn(t_wd_flg *fl)
{
	fl->len += write(1, "%", 1);
	while (fl->wd-- > 1)
		fl->len += write(1, " ", 1);
}

static void		ft_printf_perc_right_algn(t_wd_flg *fl)
{
	while (fl->wd-- > 1)
	{
		if (fl->is_zero)
			fl->len += write(1, "0", 1);
		else
			fl->len += write(1, " ", 1);
	}
	fl->len += write(1, "%", 1);
}

void			ft_print_percent(char c, t_wd_flg *fl)
{
	if (c == '%')
	{
		if (fl->lft_algn)
			ft_print_perc_left_algn(fl);
		else
			ft_printf_perc_right_algn(fl);
	}
}
