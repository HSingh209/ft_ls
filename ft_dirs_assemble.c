#include "ft_ls_hd.h" //change later to be in "inc" folder!

int 	ft_isdir(const char *path, t_dir_info *dir)
 {
 	struct stat file_inf;

	if (lstat(path, &file_inf) != 0)
	{
		printf("ls: %s: No such file or directory\n", path);//error (stat will return -1) due to no file found called *path)
		dir->err_nf = 1;
		return (0);
	}
	else
		dir->err_nf = 0;
	return (S_ISDIR(file_inf.st_mode) && !S_ISLNK(file_inf.st_mode));
}


t_dir_info	*ft_new_chdir(char *name, char *path, t_node *flags, size_t *tot)
{
	t_dir_info	*dir;

	dir = (t_dir_info *)malloc(sizeof(t_dir_info));
	dir->name = name;
	dir->path = path;
	dir->total = 0;
	dir->next = NULL;
	dir->children = NULL;
//	printf("pre get_d info\n");
	if (ft_isdir(path, dir))
		ft_get_d_info(dir, flags, tot);
	return (dir);
}

void	ft_push(t_dir_info **curr, t_dir_info *new)
{
	new->next = *curr;
	*curr = new;
}

char	*ft_setPath_fs(char *name, char *path)
{
	char	*tmp;
	char	*result;
	int 	len;

	if (name[0] == '/')
		return (ft_strdup(name));
	len = ft_strlen(path);
	if (path[len - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		result = ft_strjoin(tmp, name);
		ft_strdel(&tmp);
	}
	else
		result = ft_strjoin(path, name);
	return (result);
}