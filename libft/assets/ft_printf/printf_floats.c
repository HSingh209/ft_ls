/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:14:11 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:39:29 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_print_float_left(char *s, t_wd_flg *fl)
{
	int		i;

	i = ft_strlen(s);
	fl->len += write(1, s, i);
	while (i++ < fl->wd)
		fl->len += write(1, " ", 1);
}

static void		ft_print_float_right(char *str, t_wd_flg *fl)
{
	int		i;

	i = ft_strlen(str);
	while (fl->wd > i)
	{
		if (fl->is_zero)
		{
			fl->len += write(1, "0", 1);
			i++;
		}
		else
		{
			fl->len += write(1, " ", 1);
			i++;
		}
	}
	fl->len += write(1, str, ft_strlen(str));
}

void			ft_print_floats(char c, t_wd_flg *fl, va_list typ)
{
	long double		dbl;
	char			*str;

	if (fl->ldb_flag || c == 'f')
		dbl = va_arg(typ, double);
	else if (fl->l_flag)
		dbl = va_arg(typ, double);
	else
	{
		fl->len = -1;
		return ;
	}
	if (!fl->is_snp)
		fl->prc = 6;
	str = ft_ldtoa(dbl, fl->prc);
	if (fl->lft_algn)
		ft_print_float_left(str, fl);
	else
		ft_print_float_right(str, fl);
	free(str);
}
