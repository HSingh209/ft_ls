/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:57:42 by harssing          #+#    #+#             */
/*   Updated: 2018/10/27 17:04:16 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_ch;
	char	*dst_ch;
	size_t	i;

	if (src == dst)
		return (dst);
	src_ch = (char *)src;
	dst_ch = (char *)dst;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			dst_ch[i] = src_ch[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_ch[i] = src_ch[i];
			i++;
		}
	}
	return (dst);
}
