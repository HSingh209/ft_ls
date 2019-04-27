/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:00:27 by harssing          #+#    #+#             */
/*   Updated: 2018/10/28 17:30:51 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	int		s_len;
	int		i;

	if (s && f)
	{
		i = 0;
		s_len = ft_strlen((char *)s);
		if (!(new_s = ft_strnew(s_len)))
			return (NULL);
		while (s[i])
		{
			new_s[i] = f(s[i]);
			i++;
		}
		return (new_s);
	}
	return (NULL);
}
