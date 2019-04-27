/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:09:24 by harssing          #+#    #+#             */
/*   Updated: 2018/10/29 17:16:35 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(const char *s1, const char *s2, int len1, int len2)
{
	char	*join;
	int		i1;
	int		i2;

	if (!(join = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		join[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		join[i1] = s2[i2];
		i1++;
		i2++;
	}
	join[i1] = '\0';
	return (join);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen((char *)s1);
		s2_len = ft_strlen((char *)s2);
		return (join_str(s1, s2, s1_len, s2_len));
	}
	return (NULL);
}
