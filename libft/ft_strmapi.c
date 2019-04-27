/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:37:31 by harssing          #+#    #+#             */
/*   Updated: 2018/10/28 17:46:07 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map_str;
	unsigned int	i;
	int				j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((char *)s);
		if (!(map_str = ft_strnew(j)))
			return (NULL);
		while (s[i])
		{
			map_str[i] = f(i, s[i]);
			i++;
		}
		return (map_str);
	}
	return (NULL);
}
