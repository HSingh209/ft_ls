/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:43:18 by harssing          #+#    #+#             */
/*   Updated: 2018/10/25 17:44:32 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay_stack;
	char	*nee_dle;
	size_t	n_len;

	hay_stack = (char *)haystack;
	nee_dle = (char *)needle;
	n_len = ft_strlen(nee_dle);
	if (n_len == 0)
		return ((char *)hay_stack);
	while (*hay_stack && len-- >= n_len)
	{
		if (ft_strncmp(hay_stack, nee_dle, n_len) == 0)
			return (hay_stack);
		hay_stack++;
	}
	return ((char *)NULL);
}
