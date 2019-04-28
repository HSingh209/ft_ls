#include "ft_ls_hd.h"

static t_dir_info	*ft_partition(t_dir_info *head, t_dir_info *tail, t_dir_info **head_nd,
							t_dir_info **tail_nd, t_bool (*cmp)(t_dir_info, t_dir_info))
{
	t_dir_info	*pivot_node;
	t_dir_info	*prev_dir;
	t_dir_info	*curr_dir;

	pivot_node = tail;
	prev_dir = NULL;
	curr_dir = head;
	while (curr_dir != pivot_node)
	{
		if ((*cmp)(*curr_dir, *pivot_node))
			ft_move_left(head_nd, &prev_dir, &curr_dir);
		else
			ft_move_right(&tail, &prev_dir, &curr_dir);
	}
	if ((*head_nd) == NULL)
		(*head_nd) = pivot_node;
	(*tail_nd) = tail;		//check code here, error for type confliction fixed with * added to 'tail'
	return (pivot_node);
}

static t_dir_info	*ft_quick_sort(t_dir_info *head, t_dir_info *tail, 
							t_bool (*cmp)(t_dir_info, t_dir_info))
{
	t_dir_info *head_nd;
	t_dir_info *tail_nd;
	t_dir_info *pivot;
	t_dir_info *temp;

	if (!head || head == tail)
		return (head);
	head_nd = NULL;
	tail_nd = NULL;
	pivot = ft_partition(head, tail, &head_nd, &tail_nd, (*cmp));
	if (head_nd != pivot)
	{
		temp = head_nd;
		while (temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;
		head_nd = ft_quick_sort(head_nd, temp, (*cmp));
		temp = ft_get_tail(head_nd);
		temp->next = pivot;
	}
	pivot->next = ft_quick_sort(pivot->next, tail_nd, (*cmp));
	return (head_nd);
}

static	t_bool	ft_cmp_time(t_dir_info a, t_dir_info b)
{
	t_bool cmp;

	if (a.m_time.tv_sec == b.m_time.tv_sec)
	{
		if (a.m_time.tv_nsec == b.m_time.tv_nsec)
			cmp = ft_strcmp(a.name, b.name) < 0;
		else
			cmp = a.m_time.tv_nsec > b.m_time.tv_nsec;
	}
	else
		cmp = a.m_time.tv_sec > b.m_time.tv_sec;
	return (cmp);
}

static t_bool	ft_cmp_lex(t_dir_info a, t_dir_info b)
{
	return (ft_strcmp(a.name, b.name) < 0);
}

t_dir_info 		*ft_set_tail(t_dir_info *curr)
{
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}
//This function sorts the top nodes in order or in reverse if -r flag
void	ft_sort(t_node *flags, t_dir_info **parent_dir)
{
	t_dir_info	*tail;
	t_bool		(*cmp)(t_dir_info, t_dir_info);

	if (!(*parent_dir)->next)
		return ;			//No need to sort IF only 1 dir.
	tail = ft_set_tail(*parent_dir);
//	cmp = &ft_cmp_lex;
	cmp = flags->time ? &ft_cmp_time : &ft_cmp_lex;
	*parent_dir = ft_quick_sort(*parent_dir, tail, cmp);
	if (flags->rever)
		ft_reverse_lst(parent_dir);
}