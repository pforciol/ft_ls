/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:36:17 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/19 12:01:51 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list				*lst_create(void *content, size_t size)
{
	t_list			*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		exit(ERROR);
	list->content = content;
	list->content_size = size;
	list->next = NULL;
	return (list);
}

void				lst_append(t_list **list, t_list *to_append)
{
	t_list			*tmp;

	if (!list || !(*list))
		*list = to_append;
	else
	{
		tmp = *list;
		while ((*list)->next != NULL)
			*list = (*list)->next;
		(*list)->next = to_append;
		*list = tmp;
	}
}

void				lst_clear(t_list **list)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		*list = (*list)->next;
		free(tmp->content);
		free(tmp);
		tmp = *list;
	}
	*list = NULL;
}

int					get_lst_size(t_list *list)
{
	int				size;

	size = 0;
	while (list != NULL)
	{
		size++;
		list = list->next;
	}
	return (size);
}
