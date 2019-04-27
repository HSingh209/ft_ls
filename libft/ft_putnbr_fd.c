/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:11:17 by harssing          #+#    #+#             */
/*   Updated: 2018/10/27 17:24:41 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < -9 || nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	if (nb < 0)
	{
		if (nb >= -9)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' - (nb % 10), fd);
	}
	else
		ft_putchar_fd('0' + (nb % 10), fd);
}
