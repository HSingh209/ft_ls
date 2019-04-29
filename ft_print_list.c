/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:52:04 by harssing          #+#    #+#             */
/*   Updated: 2019/04/28 17:58:38 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_hd.h"

void			ft_print_dir(t_dir_info *dir, int l_spec)
{
	if (l_spec)
		ft_print_long(dir);
	else if (dir->is_dir == 0 && dir->err_nf == 0)
		ft_printf("%s\n", dir->name);
	else if (dir->err_nf == 0)
		ft_printf("%s\n", dir->path);
	if (dir->next)
		write(1, "\n", 2);
}

void			ft_header_ls(t_dir_info *dir, t_bool is_root)
{
	if (is_root)
		ft_printf("%s:\n", dir->name);
	else
		ft_printf("%s:\n", dir->path);
}

static void		ft_children_prt_l(t_dir_info *prt_nd)
{
	t_dir_info	*child_seat;

	child_seat = prt_nd->children;
	ft_printf("total %zu\n", prt_nd->total);
	while (child_seat)
	{
		ft_print_long(child_seat);
		child_seat = child_seat->next;
	}
}

static	void	ft_print_childs(t_dir_info *children)
{
	while (children)
	{
		ft_printf("%s	", children->name);
		children = children->next;
	}
	write(1, "\n", 1);
}

void			ft_print_lists(t_node *flags, t_dir_info *parent,
				t_bool is_root)
{
	t_bool	multi;

	multi = parent->next ? true : false;
	while (parent)
	{
		if (parent->is_dir)
		{
			if (!is_root || multi)
				ft_header_ls(parent, is_root);
			if (flags->l_spec && parent->children != NULL)
				ft_children_prt_l(parent);
			else
				ft_print_childs(parent->children);
			if (flags->recur && parent->children != NULL)
			{
				write(1, "\n", 1);
				ft_print_lists(flags, parent->children, false);
			}
		}
		else if (is_root)
			ft_print_dir(parent, flags->l_spec);
		parent = parent->next;
	}
}
