/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags_ftpf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:58:26 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:34:30 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

void			ft_printer(const char *format, t_wd_flg *fl, va_list typ)
{
	if (format[fl->i] == 'c')
		ft_print_ch(format[fl->i], fl, typ);
	else if (format[fl->i] == 'd' || format[fl->i] == 'i')
		ft_print_id(format[fl->i], fl, typ);
	else if (format[fl->i] == 'o')
		ft_print_oct(fl, typ);
	else if (format[fl->i] == 'u')
		ft_print_uns_nbr(fl, typ);
	else if (format[fl->i] == 'x' || format[fl->i] == 'X')
		ft_print_hexi(format[fl->i], fl, typ);
	else if (format[fl->i] == 'p')
		ft_print_pa(fl, typ);
	else if (format[fl->i] == 's')
		ft_print_str(format[fl->i], fl, typ);
	else if (format[fl->i] == '%')
		ft_print_percent(format[fl->i], fl);
	else if (format[fl->i] == 'f')
		ft_print_floats(format[fl->i], fl, typ);
}

static	void	ft_struct_reset(t_wd_flg *xf)
{
	xf->lft_algn = 0;
	xf->wd = 0;
	xf->prc = 0;
	xf->is_hash = 0;
	xf->is_zero = 0;
	xf->lft_algn = 0;
	xf->show_sign = 0;
	xf->is_space = 0;
	xf->l_flag = 0;
	xf->ll_flag = 0;
	xf->ldb_flag = 0;
	xf->h_flag = 0;
	xf->hh_flag = 0;
	xf->is_snp = 0;
}

void			ft_parse_flags(const char *format, t_wd_flg *fl, va_list typ)
{
	while (format[fl->i] != '\0')
	{
		if (format[fl->i] == '%')
		{
			fl->i++;
			if (ft_strchr("#-+ .0123456789hljzL", format[fl->i]))
				ft_parse_modif(format, fl);
			if (ft_strchr("scpdDiouxXf%", format[fl->i]))
			{
				ft_printer(format, fl, typ);
				if (fl->len == -1)
					return ;
				ft_struct_reset(fl);
			}
		}
		else
			fl->len += write(1, &format[fl->i], 1);
		fl->i++;
	}
}
