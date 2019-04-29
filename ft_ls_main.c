/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:19:30 by harssing          #+#    #+#             */
/*   Updated: 2019/04/28 16:36:27 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_hd.h"

void			ft_get_each_family(t_node *flags, t_dir_info *parent_dn)
{
	while (parent_dn)
	{
		if (parent_dn->is_dir)
		{
			parent_dn->children = ft_set_child_nodes(parent_dn->path, flags,
				&parent_dn->total);
			parent_dn = parent_dn->next;
		}
		else
			parent_dn = parent_dn->next;
	}
}

static void		ft_sort_sub_dirs(t_node *flags, t_dir_info *parent_dirs)
{
	t_dir_info *temp;

	while (parent_dirs)
	{
		if (parent_dirs->children != NULL)
			ft_sort(flags, &parent_dirs->children);
		if (flags->recur)
		{
			temp = parent_dirs->children;
			while (temp)
			{
				if (temp->is_dir == 1)
					ft_sort_sub_dirs(flags, temp);
				temp = temp->next;
			}
		}
		parent_dirs = parent_dirs->next;
	}
}

static void		ft_ls(t_node *flags, t_dir_info *parent_dir)
{
	ft_get_each_family(flags, parent_dir);
		ft_printf("test_get_eachFam passed\n");//delete comments and change all printf to ft_printf
	ft_sort_sub_dirs(flags, parent_dir);
	ft_print_lists(flags, parent_dir, true);
}

t_dir_info		*ft_make_nodes(char **av, t_node *flags)
{
	size_t		i;
	t_dir_info	*ll;
	char		*path;
	size_t		temp;

	i = 1;
	ll = NULL;
	while (av[i] && *(*(av + i) + 0) == '-')
		i++;
	if (av[i])
	{
		path = ft_setpath_fs(av[i], "./");
		ll = ft_new_chdir(ft_strdup(av[i]), path, flags, &temp);
		i++;
		while (av[i])
		{
			path = ft_setpath_fs(av[i], "./");
			ft_push(&ll, ft_new_chdir((ft_strdup(av[i])), path, flags, &temp));
			i++;
		}
	}
	else
		ll = ft_new_chdir(ft_strdup("./"), ft_strdup("./"), flags, &temp);
	return (ll);
}

int				main(int ac, const char **av)
{
	t_node		*flags;
	t_dir_info	*dir_list;

	if (ac > 0)
	{
		flags = ft_ls_flags(av);
		dir_list = ft_make_nodes((char**)av, flags);
		ft_printf("is dir? === %i\n", dir_list->is_dir);//Dont forget to check all printfs are ft_printf & comments
		ft_sort(flags, &dir_list);
		ft_ls(flags, dir_list);
		ft_free_flags(&flags);
		ft_free_dirs(&dir_list);
	}
	return (0);
}
