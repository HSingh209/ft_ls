/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:54:13 by harssing          #+#    #+#             */
/*   Updated: 2018/10/25 13:58:14 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen((char *)s);
	while (s_len != 0 && s[s_len] != (char)c)
		s_len--;
	if (s[s_len] == (char)c)
		return ((char *)&s[s_len]);
	return (NULL);
}
