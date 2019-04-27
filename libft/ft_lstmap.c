/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 22:35:38 by harssing          #+#    #+#             */
/*   Updated: 2018/10/30 22:41:44 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map_lst;

	if (lst)
	{
		map_lst = f(lst);
		map_lst->next = ft_lstmap(lst->next, f);
		return (map_lst);
	}
	return (NULL);
}
