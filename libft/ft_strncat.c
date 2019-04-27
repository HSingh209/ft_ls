/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 23:17:02 by harssing          #+#    #+#             */
/*   Updated: 2018/10/24 23:17:07 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[a] != '\0' && a < n)
		s1[i++] = s2[a++];
	s1[i] = '\0';
	return (s1);
}
