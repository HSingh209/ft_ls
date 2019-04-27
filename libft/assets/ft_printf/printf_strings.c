/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:58:01 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:33:13 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_print_string_left(char *str, t_wd_flg *fl)
{
	int		s_len;

	if (!str)
		str = "(null)";
	s_len = ft_strlen(str);
	if (fl->prc && s_len > 0 && s_len > fl->prc)
		s_len = fl->prc;
	fl->len += write(1, str, s_len);
	while (fl->wd-- > s_len)
		fl->len += write(1, " ", 1);
}

static void		ft_print_string_right(char *str, t_wd_flg *fl)
{
	int		s_len;

	if (!str)
		str = "(null)";
	s_len = ft_strlen(str);
	if (fl->is_snp && s_len > 0 && s_len > fl->prc)
		s_len = fl->prc;
	while (fl->wd > s_len)
	{
		if (fl->is_zero)
			fl->len += write(1, "0", 1);
		else
			fl->len += write(1, " ", 1);
		fl->wd--;
	}
	fl->len += write(1, str, s_len);
}

void			ft_print_str(char c, t_wd_flg *fl, va_list typ)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(typ, char *);
		if (fl->lft_algn)
			ft_print_string_left(str, fl);
		else
			ft_print_string_right(str, fl);
	}
}
