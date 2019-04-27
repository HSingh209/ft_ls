/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 00:15:53 by harssing          #+#    #+#             */
/*   Updated: 2018/09/17 00:18:23 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *temp;

	temp = b;
	if (len)
	{
		while (len--)
		{
			*temp = (unsigned char)c;
			temp++;
		}
	}
	return (b);
}
