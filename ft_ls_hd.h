
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

# define A_OP(str, a) (*(str) != '.' || a)

typedef	enum
{
	false,
	true
}	t_bool;

typedef struct	s_node
{
	int	prefix_dirs;
	int	file_name;
	int is_file;
	int	found_flag;
	t_bool	all: 1;
	int	recur;
	int	l_spec;
	int	time;
	int rever;
}		t_node;

typedef struct		s_dir_node	//The input from args
{
 	struct s_dir_node		*next;		
 	char			*name;				//Why do I have name AND path here ?
 	char			*path;
	int 			is_dir;
}					t_dir_node;

typedef struct s_dir_info
{
	int 				is_not_file;
	int 				err_nf;
	int					is_dir;
	char 				*permissions;
	size_t				total;	//changing to 'int' due to error with type conflict of size_t
	nlink_t				links;
	char				*owner;
	char				*group;
	off_t				size;
	struct timespec		mtime;
	char				*name;
	char				*path;
	struct s_dir_info	*next;
	struct s_dir_info	*children;

}						t_dir_info;

// typedef struct 	s_dirlist
// {
// 		char 				*name;
// 		t_node 				*head;
// 		size_t 				total;
// 		struct s_dirlist 	*next;
//}							t_dirlist;
void	ft_push(t_dir_info **curr, t_dir_info *new);
void	ft_sort(t_node *flags, t_dir_info **parent_dir);
t_dir_info	*ft_get_tail(t_dir_info	*current);
void	ft_reverse_lst(t_dir_info **dir);
void	ft_move_left(t_dir_info **head, t_dir_info	**prev, t_dir_info **curr);
void	ft_move_right(t_dir_info **tail, t_dir_info **prev, t_dir_info **curr);

int 	ft_isdir(const char *path, t_dir_info *dir);


//static char		*ft_parse_persmiss(mode_t st_mode);
//static void		ft_set_link(char *path, char **link, size_t size);

void	ft_strdel(char **as);
int 	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_setPath_fs(char *name, char *path);

void	ft_get_d_info(t_dir_info *dir, t_node *flags, size_t *tot);

t_dir_info	*ft_set_childNodes(char *path, t_node *flags, size_t *tot);
t_dir_info	*ft_new_chdir(char *name, char *path, t_node *flags, size_t *tot);

void	ft_sort(t_node *flags, t_dir_info **parent_dir);

t_dir_info	*ft_set_childNodes(char *path, t_node *flags, size_t *tot);

void	ft_print_lists(t_node *flags, t_dir_info *parent, t_bool is_root);


//static t_dir_info	*ft_quick_sort(t_dir_info *head, t_dir_info *tail, 
//							t_bool (*cmp)(t_dir_info, t_dir_info));

//int 	parse_input(char *str_init, t_node *info, struct stat *f_struct);
t_node	*ft_ls_flags(const char **av);

#endif
