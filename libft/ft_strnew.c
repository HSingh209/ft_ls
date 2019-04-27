/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:34:38 by harssing          #+#    #+#             */
/*   Updated: 2018/10/27 19:43:07 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}
