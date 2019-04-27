/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:13:56 by harssing          #+#    #+#             */
/*   Updated: 2018/10/29 16:15:48 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start_i;
	size_t	len_i;
	char	*trim_str;

	if (s)
	{
		start_i = 0;
		while (s[start_i] == ' ' || s[start_i] == '\n' || s[start_i] == '\t')
			start_i++;
		if (s[start_i] == '\0')
			return (ft_strdup(s + start_i));
		len_i = ft_strlen(s) - 1;
		while (s[len_i] == ' ' || s[len_i] == '\n' || s[len_i] == '\t')
			len_i--;
		if (!(trim_str = (char*)malloc(sizeof(char) * len_i - start_i + 1)))
			return (NULL);
		return (trim_str = ft_strsub(s, start_i, len_i - start_i + 1));
	}
	return (NULL);
}
