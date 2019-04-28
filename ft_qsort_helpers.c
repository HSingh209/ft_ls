#include "ft_ls_hd.h"

void	ft_free_dirs(t_dir_info **dirs)
{
	t_dir_info *curr;
	t_dir_info *next;

	curr = *dirs;
	while (curr != NULL)
	{
		if (curr->children != NULL)
			ft_free_dirs(&curr->children);
		next = curr->next;
		ft_strdel(&curr->name);
		ft_strdel(&curr->path);
		if (curr->is_dir != 0)
			ft_strdel(&curr->permissions);
		free(curr);
		curr = next;
	}
	*dirs = NULL;
}

void	ft_move_left(t_dir_info **head, t_dir_info	**prev, t_dir_info **curr)
{
	if ((*head) == NULL)
		(*head) = *curr;
	*prev = *curr;
	*curr = (*curr)->next;
}

void	ft_move_right(t_dir_info **tail, t_dir_info **prev, t_dir_info **curr)
{
	t_dir_info	*temp;

	if (*prev)
		(*prev)->next = (*curr)->next;
	temp = (*curr)->next;
	(*curr)->next = NULL;
	(*tail)->next = (*curr);
	(*tail) = (*curr);
	(*curr) = temp;
}

void	ft_reverse_lst(t_dir_info **dir)
{
	t_dir_info *current;
	t_dir_info *prev;
	t_dir_info *next;

	current = *dir;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*dir = prev;
}

t_dir_info	*ft_get_tail(t_dir_info	*current)
{
	while (current && current->next)
		current = current->next;
	return (current);
}