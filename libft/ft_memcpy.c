/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:24:13 by harssing          #+#    #+#             */
/*   Updated: 2018/10/24 23:32:02 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*restrict dst, const void *restrict src, size_t n)
{
	char		*dtemp;
	const char	*stemp;

	dtemp = dst;
	stemp = src;
	while (n--)
		*dtemp++ = *stemp++;
	return (dst);
}
