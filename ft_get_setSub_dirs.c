#include "ft_ls_hd.h"

char	*ft_make_npath(char *name, char *path)
{
	char	*temp;
	char	*result;
	int		len;

	if (name[0] == '/')
		return (name);	//use ft_strdup here ?
	len = ft_strlen(path);
	if (path[len - 1] != '/')
	{
		temp = ft_strjoin(path, "/");
		result = ft_strjoin(temp, name);
		ft_strdel(&temp);
	}
	else
		result = ft_strjoin(path, name);
	return (result);
}

static t_dir_info	*ft_get_Cnodes(char *path_in, t_node *flags, size_t *tot,
										DIR *dirstream)
{
	t_dir_info		*chilnodes;
	struct dirent	*curr_info;
	char			*name;
	char			*path;

	chilnodes = NULL;
	while ((curr_info = readdir(dirstream)))
	{
		if (*curr_info->d_name != '.')//flags->all))	//check for source code on how this is done (CHANGED)
		{
			name = ft_strdup(curr_info->d_name); //Why do i need 'strdup'
			path = ft_make_npath(name, path_in);
			if (chilnodes != NULL)
				ft_push(&chilnodes, ft_new_chdir(name, path, flags, tot));
			else
				chilnodes = ft_new_chdir(name, path, flags, tot);
			if ((chilnodes->is_dir == 1) && (flags->recur == 1) && 
						(ft_strcmp(name, ".") && ft_strcmp(name, "..")))
				chilnodes->children = ft_set_childNodes(chilnodes->path, flags
													, &chilnodes->total);
		}
	}
	return (chilnodes);
}

t_dir_info	*ft_set_childNodes(char *path, t_node *flags, size_t *tot)	//changing tot to int from size_t [WED 4 PM]
{
	DIR 		*dirstream;
	t_dir_info	*fam;

	fam = NULL;
	dirstream = opendir(path);
	if (dirstream == NULL)
		return (NULL);
	fam = ft_get_Cnodes(path, flags, tot, dirstream);
	closedir(dirstream);
	return (fam);
}