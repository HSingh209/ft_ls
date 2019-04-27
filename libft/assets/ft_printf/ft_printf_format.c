/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:53:17 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 15:24:29 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hprintf.h"

int			ft_printf(const char *format, ...)
{
	t_wd_flg	flg;
	va_list		typ;

	ft_bzero(&flg, sizeof(t_wd_flg));
	va_start(typ, format);
	if (format[0] == '%' && format[1] == '\0')
		;
	else if (!ft_strchr(format, '%'))
		flg.len += write(1, format, ft_strlen(format));
	else
		ft_parse_flags(format, &flg, typ);
	va_end(typ);
	return (flg.len);
}
