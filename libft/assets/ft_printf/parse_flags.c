/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:56:55 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:30:26 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

static void		ft_lenfl(const char *format, t_wd_flg *fl)
{
	if (ft_strchr("hljzL", format[fl->i]))
	{
		if (format[fl->i] == 'h')
		{
			if (format[fl->i + 1] == 'h')
				fl->hh_flag = 1;
			else
				fl->h_flag = 1;
		}
		else if (format[fl->i] == 'l')
		{
			if (format[fl->i + 1] == 'l')
				fl->ll_flag = 1;
			else
				fl->l_flag = 1;
		}
		else if (format[fl->i] == 'L')
			fl->ldb_flag = 1;
		while (ft_strchr("hljzL", format[fl->i]))
			fl->i++;
	}
}

static void		ft_get_precision(const char *format, t_wd_flg *fl)
{
	if (format[fl->i] == '.')
	{
		fl->i++;
		fl->is_snp = 1;
		if (ft_isdigit(format[fl->i]))
		{
			fl->prc = ft_atoi(&format[fl->i]);
			while (ft_isdigit(format[fl->i]))
				fl->i++;
		}
	}
}

static void		ft_get_width(const char *format, t_wd_flg *fl)
{
	if (ft_isdigit(format[fl->i]))
	{
		fl->wd = ft_atoi(&format[fl->i]);
		while (ft_isdigit(format[fl->i]))
			fl->i++;
	}
}

static void		ft_flag_search(const char *format, t_wd_flg *fl)
{
	while (ft_strchr("-+ 0#", format[fl->i]))
	{
		if (format[fl->i] == '-')
			fl->lft_algn = 1;
		else if (format[fl->i] == '+')
			fl->show_sign = 1;
		else if (format[fl->i] == ' ')
			fl->is_space = 1;
		else if (format[fl->i] == '0')
			fl->is_zero = 1;
		else if (format[fl->i] == '#')
			fl->is_hash = 1;
		fl->i++;
	}
	(fl->show_sign) ? (fl->is_space = 0) : 0;
}

void			ft_parse_modif(const char *format, t_wd_flg *fl)
{
	ft_flag_search(format, fl);
	ft_get_width(format, fl);
	ft_get_precision(format, fl);
	ft_lenfl(format, fl);
}
