/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_hd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:32:24 by harssing          #+#    #+#             */
/*   Updated: 2019/04/29 17:03:46 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HD_H
# define FT_LS_HD_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <string.h>
# include <time.h>
# include <dirent.h>

# define SIXMONTHS ((365 / 2) * 86400)

typedef	enum
{
	false,
	true
}	t_bool;

typedef struct			s_node
{
	int					prefix_dirs;
	int					file_name;
	int					is_file;
	int					found_flag;
	t_bool				all: 1;
	int					recur;
	int					l_spec;
	int					time;
	int					rever;
}						t_node;

typedef struct			s_dir_info
{
	int					is_not_file;
	int					err_nf;
	int					is_dir;
	char				*permissions;
	size_t				total;
	nlink_t				links;
	char				*owner;
	char				*group;
	off_t				size;
	struct timespec		m_time;
	char				*name;
	char				*path;
	struct s_dir_info	*next;
	struct s_dir_info	*children;
	t_bool				(*cmp)(struct s_dir_info, struct s_dir_info);
}						t_dir_info;

void					ft_push(t_dir_info **curr, t_dir_info *new);
void					ft_sort(t_node *flags, t_dir_info **parent_dir);
t_dir_info				*ft_set_tail(t_dir_info	*curr);
t_dir_info				*ft_get_tail(t_dir_info	*current);
void					ft_reverse_lst(t_dir_info **dir);
void					ft_move_left(t_dir_info **head, t_dir_info	**prev,
						t_dir_info **curr);
void					ft_move_right(t_dir_info **tail, t_dir_info **prev,
						t_dir_info **curr);
int						ft_isdir(const char *path, t_dir_info *dir);
void					ft_print_long(t_dir_info *dir);
void					ft_free_flags(t_node **flags);
void					ft_free_dirs(t_dir_info **dirs);
char					*ft_setpath_fs(char *name, char *path);
void					ft_get_d_info(t_dir_info *dir, t_node *flags,
						size_t *tot);
t_dir_info				*ft_set_child_nodes(char *path, t_node *flags,
						size_t *tot);
t_dir_info				*ft_new_chdir(char *name, char *path, t_node *flags,
						size_t *tot);
void					ft_sort(t_node *flags, t_dir_info **parent_dir);
void					ft_print_lists(t_node *flags, t_dir_info *parent,
						t_bool is_root);
t_dir_info				*ft_quick_sort_t(t_dir_info *head, t_dir_info *tail);
t_bool					ft_cmp_time(t_dir_info a, t_dir_info b);
t_node					*ft_ls_flags(const char **av);

#endif
