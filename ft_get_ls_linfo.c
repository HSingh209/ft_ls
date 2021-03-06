/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ls_linfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:48:29 by harssing          #+#    #+#             */
/*   Updated: 2019/04/28 17:51:32 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_hd.h"

static char		*ft_parse_old(char *dir_time)
{
	char	*result;
	int		i;

	i = -1;
	result = (char *)malloc(11);
	while (i++ < 6)
		*(result + i) = *(dir_time + (4 + i));
	while (i < 11)
	{
		*(result + i) = *(dir_time + (13 + i));
		i++;
	}
	*(result + i) = '\0';
	return (result);
}

static char		*ft_parse_recent(char *dir_time)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(12);
	while (i++ < 11)
		*(ret + i) = *(dir_time + (4 + i));
	*(ret + i) = '\0';
	return (ret);
}

char			*ft_parse_dtime(struct timespec m_time)
{
	static time_t	now;
	char			*dir_time;

	now = time(NULL);
	dir_time = ctime(&m_time.tv_sec);
	if (m_time.tv_sec + (SIXMONTHS) > now && m_time.tv_sec < now + SIXMONTHS)
	{
		return (ft_parse_recent(dir_time));
	}
	else
	{
		return (ft_parse_old(dir_time));
	}
}

void			ft_print_long(t_dir_info *dir)
{
	char	*dir_time_stamp;

	dir_time_stamp = ft_parse_dtime(dir->m_time);
	ft_printf("%s %d %s %s %lld %s %s\n", dir->permissions, dir->links,
		dir->owner, dir->group, dir->size, dir_time_stamp, dir->name);
	ft_strdel(&dir_time_stamp);
}
