/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:24:04 by harssing          #+#    #+#             */
/*   Updated: 2018/10/24 23:28:05 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tempd;
	unsigned char	*tempsc;

	i = 0;
	tempd = (unsigned char *)dst;
	tempsc = (unsigned char *)src;
	while (i < n)
	{
		tempd[i] = tempsc[i];
		if (tempsc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
