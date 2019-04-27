/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:20:15 by harssing          #+#    #+#             */
/*   Updated: 2018/10/29 16:20:43 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(const char *trim_s, int i, char c)
{
	int		wordlen;

	wordlen = 0;
	while (trim_s[i + wordlen] && (trim_s[i + wordlen] != c))
		wordlen++;
	return (wordlen);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		a;
	char	**str_array;
	char	*trim_s;

	if (!c || !s || !(str_array = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	trim_s = ft_strtrim(s);
	i = 0;
	a = 0;
	while (trim_s[i])
	{
		if (trim_s[i] == c)
			i++;
		else
		{
			str_array[a++] = ft_strsub(trim_s, i, getlen(trim_s, i, c));
			i = i + getlen(trim_s, i, c);
		}
	}
	str_array[a] = 0;
	return (str_array);
}
