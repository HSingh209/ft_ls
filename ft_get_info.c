/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:44:40 by harssing          #+#    #+#             */
/*   Updated: 2019/04/28 17:47:35 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_hd.h"

static void		ft_set_link(char *path, char **link, size_t size)
{
	char	*linkname;
	char	*tmp;

	linkname = malloc(size);
	readlink((const char *)path, linkname, size);
	linkname[size] = '\0';
	tmp = ft_strjoin(*link, " -> ");
	ft_strdel(link);
	ft_strdel(&tmp);
	*link = linkname;
}

static char		ft_getdescriptor(mode_t m)
{
	if ((m & S_IFMT) == S_IFREG)
		return ('-');
	else if ((m & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((m & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((m & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((m & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((m & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((m & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('0');
}

static char		*ft_parse_permiss(mode_t st_mode)
{
	char *permissions;

	permissions = malloc(11);
	*(permissions + 0) = ft_getdescriptor(st_mode);
	*(permissions + 1) = (st_mode & S_IRUSR) ? 'r' : '-';
	*(permissions + 2) = (st_mode & S_IWUSR) ? 'w' : '-';
	*(permissions + 3) = (st_mode & S_IXUSR) ? 'x' : '-';
	*(permissions + 4) = (st_mode & S_IRGRP) ? 'r' : '-';
	*(permissions + 5) = (st_mode & S_IWGRP) ? 'w' : '-';
	*(permissions + 6) = (st_mode & S_IXGRP) ? 'x' : '-';
	*(permissions + 7) = (st_mode & S_IROTH) ? 'r' : '-';
	*(permissions + 8) = (st_mode & S_IWOTH) ? 'w' : '-';
	*(permissions + 9) = (st_mode & S_IXOTH) ? 'x' : '-';
	*(permissions + 10) = '\0';
	return (permissions);
}

void			ft_get_d_info(t_dir_info *dir, t_node *flags, size_t *tot)
{
	struct stat	dir_stats;

	lstat(dir->path, &dir_stats);
	dir->is_dir = S_ISDIR(dir_stats.st_mode) && !S_ISLNK(dir_stats.st_mode);
	if (dir->err_nf != 1)
	{
		dir->permissions = ft_parse_permiss(dir_stats.st_mode);
		dir->links = dir_stats.st_nlink;
		dir->owner = getpwuid(dir_stats.st_uid)->pw_name;
		dir->group = getgrgid(dir_stats.st_gid)->gr_name;
		dir->size = dir_stats.st_size;
		*tot += (size_t)dir_stats.st_blocks;
		dir->m_time = dir_stats.st_mtimespec;
		if (S_ISLNK(dir_stats.st_mode) && flags->l_spec)
			ft_set_link(dir->path, &dir->name, (size_t)(dir_stats.st_size + 1));
	}
}
