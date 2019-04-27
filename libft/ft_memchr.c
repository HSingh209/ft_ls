/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:12:37 by harssing          #+#    #+#             */
/*   Updated: 2018/10/24 23:13:08 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t_str;

	t_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (t_str[i] != (unsigned char)c)
			i++;
		else
			return (t_str + i);
	}
	return (NULL);
}
