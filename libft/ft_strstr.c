/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:10:51 by harssing          #+#    #+#             */
/*   Updated: 2018/10/25 14:54:33 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n_len;
	char	*hay_temp;
	char	*nee_temp;

	nee_temp = (char *)needle;
	n_len = ft_strlen(nee_temp);
	hay_temp = (char *)haystack;
	if (n_len == 0)
		return ((char *)haystack);
	while (*hay_temp)
	{
		if (ft_strncmp(hay_temp, nee_temp, n_len) == 0)
		{
			return (hay_temp);
		}
		hay_temp++;
	}
	return ((char *)NULL);
}
