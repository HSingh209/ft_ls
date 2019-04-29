/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 18:02:47 by harssing          #+#    #+#             */
/*   Updated: 2019/04/28 18:06:43 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_hd.h"

void			ft_free_flags(t_node **flags)
{
	free(*flags);
	*flags = NULL;
}

static	t_bool	ft_valid_flag(const char *args)
{
	int i;

	i = 0;
	if (args[i] != '-')
		return (false);
	i++;
	while (args[i])
	{
		if (args[i] == 'R' || args[i] == 'a' || args[i] == 't' ||
			args[i] == 'r' || args[i] == 'l')
			i++;
		else
		{
			printf("ft_ls: illegal option -- %c\n", args[i]);
			printf("usage: ft_ls [-Ralrt] [file ...]");
			return (false);
		}
	}
	return (true);
}

static t_node	*ft_new_flg(void)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->l_spec = 0;
	new->recur = 0;
	new->time = 0;
	new->rever = 0;
	new->all = false;
	return (new);
}

t_node			*ft_ls_flags(const char **av)
{
	size_t i;
	t_node *flags;

	flags = ft_new_flg();
	i = 1;
	while (av[i] && *(*(av + i) + 0) == '-')
	{
		if (ft_valid_flag(av[i]))
		{
			flags->rever = (ft_strchr(av[i], 'r') ? 1 : 0);
			flags->time = (ft_strchr(av[i], 't') ? 1 : 0);
			flags->recur = ft_strchr(av[i], 'R') ? 1 : 0;
			flags->all = ft_strchr(av[i], 'a') ? true : false;
			flags->l_spec = ft_strchr(av[i], 'l') ? 1 : 0;
			i++;
		}
		else
			exit(1);
	}
	return (flags);
}
