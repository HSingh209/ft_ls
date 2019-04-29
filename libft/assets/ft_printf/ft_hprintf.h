/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 23:17:32 by harssing          #+#    #+#             */
/*   Updated: 2019/02/26 14:51:57 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPRINTF_H
# define FT_HPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../../libft.h"

typedef struct	s_wd_flg
{
	int			is_snp;
	int			lft_algn;
	int			show_sign;
	int			is_space;
	int			is_hash;
	int			is_typ_o;
	int			is_zero;
	int			wd;
	int			prc;
	char		*len_flg;
	int			h_flag;
	int			hh_flag;
	int			l_flag;
	int			ll_flag;
	int			ldb_flag;
	int			len;
	int			i;
}				t_wd_flg;

void			ft_parse_flags(const char *format, t_wd_flg *fl, va_list typ);
void			ft_print_ch(char c, t_wd_flg *fl, va_list typ);
void			ft_parse_modif(const char *format, t_wd_flg *fl);
void			ft_print_id(char c, t_wd_flg *fl, va_list typ);
void			ft_print_oct(t_wd_flg *fl, va_list typ);
void			ft_print_uns_nbr(t_wd_flg *fl, va_list typ);
void			ft_print_hexi(char c, t_wd_flg *fl, va_list typ);
void			ft_print_pa(t_wd_flg *fl, va_list typ);
void			ft_print_str(char c, t_wd_flg *fl, va_list typ);
void			fr_print_float(char c, t_wd_flg *fl, va_list typ);
int				ft_signed_num_len(intmax_t value, int base);
void			ft_right_alg_pad(int n_len, int neg, t_wd_flg *fl);
void			ft_pad_left_align(int n_len, t_wd_flg *f);
int				ft_itoa_base(intmax_t val, int base);
int				ft_unsigned_n_len(intmax_t value, int base);
int				ft_uitoa_base(uintmax_t val, int base, char x);
void			ft_padding_ou(int n_len, t_wd_flg *fl);
void			ft_print_percent(char c, t_wd_flg *fl);
void			ft_print_floats(char c, t_wd_flg *fl, va_list typ);
char			*ft_ldtoa(double n, int precision);

#endif
