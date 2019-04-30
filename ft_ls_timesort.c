/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_timesort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harssing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:48:09 by harssing          #+#    #+#             */
/*   Updated: 2019/04/29 16:58:36 by harssing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_hd.h"

static t_dir_info	*ft_partition_t(t_dir_info *head, t_dir_info *tail,
t_dir_info **head_nd, t_dir_info **tail_nd)
{
	t_dir_info	*pivot_node;
	t_dir_info	*prev_dir;
	t_dir_info	*curr_dir;

	pivot_node = tail;
	prev_dir = NULL;
	curr_dir = head;
	while (curr_dir != pivot_node)
	{
		if (ft_cmp_time(*curr_dir, *pivot_node))
			ft_move_left(head_nd, &prev_dir, &curr_dir);
		else
			ft_move_right(&tail, &prev_dir, &curr_dir);
	}
	if ((*head_nd) == NULL)
		(*head_nd) = pivot_node;
	(*tail_nd) = tail;
	return (pivot_node);
}

t_dir_info			*ft_quick_sort_t(t_dir_info *head, t_dir_info *tail)
{
	t_dir_info *head_nd;
	t_dir_info *tail_nd;
	t_dir_info *pivot;
	t_dir_info *temp;

	if (!head || head == tail)
		return (head);
	head_nd = NULL;
	tail_nd = NULL;
	pivot = ft_partition_t(head, tail, &head_nd, &tail_nd);
	if (head_nd != pivot)
	{
		temp = head_nd;
		while (temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;
		head_nd = ft_quick_sort_t(head_nd, temp);
		temp = ft_get_tail(head_nd);
		temp->next = pivot;
	}
	pivot->next = ft_quick_sort_t(pivot->next, tail_nd);
	return (head_nd);
}
