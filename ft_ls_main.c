#include "ft_ls_hd.h"

/*static t_dir_info	*ft_errNF(char *name)
{
	printf("ft_ls: %s: No such file or directory ft_errNF\n", name);
	return (NULL);
}*/

/*This function will create a list of the nodes that are inside
each input given as args for ft_ls "Family being the arg_input"*/
void	ft_get_eachFamily(t_node *flags, t_dir_info *parent_dn)
{
//	printf("%s\n", parent_dn->name);
	while (parent_dn)
	{
		if (parent_dn->is_dir)
		{
			parent_dn->children = ft_set_childNodes(parent_dn->path, flags,
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

static void		ft_ls (t_node *flags, t_dir_info *parent_dir)
{
//	parent_dir->is_not_file = 1;
	ft_get_eachFamily(flags, parent_dir);
	printf("test_get_eachFam passed\n");
	ft_sort_sub_dirs(flags, parent_dir);	//in file: ft_sort_sub_dirs.c
	ft_print_lists(flags, parent_dir, true);
}

//Here we are calling make_nodes to set up the linked_list structure to be sorted then printed
t_dir_info 	*ft_make_nodes(char **av, t_node *flags)
{
	size_t		i;
	t_dir_info	*linked_lst;
	char		*path;
	size_t 		temp;

	i = 1;//We start with the first arg in av index [1] not 0
	linked_lst = NULL;//start list with an empty node
	//Place if statement here to check for the "--" in case it's passed in for 'dir_name'
	while (av[i] && *(*(av + i) + 0) == '-')//here we are checking '-flag'
		i++;	//use the parse_flags function from first ls code
	if (av[i])	//While there are argv passed in, create a list to work with
	{
		printf("test HERE\n");
		path = ft_setPath_fs(av[i], "./");
		linked_lst = ft_new_chdir(ft_strdup(av[i]), path, flags, &temp);
	printf("test2\n");
		i++;
		while (av[i])
		{
			path = ft_setPath_fs(av[i], "./");
			ft_push(&linked_lst, ft_new_chdir((av[i]), path, flags, &temp));	//removed ft_strdup(av[i])
			i++;
		}
	}
	else
		linked_lst = ft_new_chdir(ft_strdup("./"), ft_strdup("./"), flags, &temp);
	return (linked_lst);
}

int		main(int ac, const char **av)	//main only calls functions based on input at cmdline
{
	t_node		*flags;	//STRUCT ONLY (not linked list, reused per instance)
	t_dir_info	*dir_list;//LINKED LIST of all the expected directory lists
	
	//flags = NULL;
	if (ac > 0)
	{
		flags = ft_ls_flags(av);//set flags as 0 based on first ls_code
		dir_list = ft_make_nodes((char**)av, flags);
		//Do check here to see if the dir_list is_dir-> == 1 ?
		printf("is dir? === %i\n", dir_list->is_dir);
	//	dir_list->is_dir != 0 ? ft_sort(flags, &dir_list) : 0; //Then if the... 
		ft_sort(flags, &dir_list);	//Sort the dir_list so we can print in the correct order
	//	dir_list->is_dir != 0 ? ft_ls(flags, dir_list) : 0;
		ft_ls(flags, dir_list);
		//	printf("err_nf? === %i\n", dir_list->err_nf);
		//			printf("nf? === %i\n", dir_list->is_not_file);
		//	dir_list->is_dir == 0 && dir_list->err_nf == 0 
		//	? printf("%s\n", dir_list->name) : 0;
	//	ft_free_flags(&flags);
	//	ft_free_dirs(&dir_list);
	}
	return (0);
}