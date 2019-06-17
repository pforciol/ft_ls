/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:17:15 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/17 16:46:53 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ls_get_columns_widths(t_list *l_args, unsigned int *widths)
{
	t_data			*tmp;

	ft_bzero(widths, sizeof(int) * 7);
	while (l_args)
	{
		tmp = (t_data *)l_args->content;
		widths[0] = MAX(ft_intlen(tmp->n_link), (int)widths[0]);
		widths[1] = MAX(ft_strlen(tmp->uid.pw_name), widths[1]);
		widths[2] = MAX(ft_strlen(tmp->gid.gr_name), widths[2]);
		widths[3] = MAX(ft_intlen(tmp->size), (int)widths[3]);
		widths[4] = MAX(ft_intlen(major(tmp->rdev)), (int)widths[4]);
		widths[5] = MAX(ft_intlen(minor(tmp->rdev)), (int)widths[5]);
		widths[6] = S_ISBLK(tmp->mode) || S_ISCHR(tmp->mode) ? 1 : 0;
		l_args = l_args->next;	
	}
}

t_list				*ls_append_parent(t_list *parent, t_list *l_args)
{
	char			*parent_path;
	char			*parent_name;
	char			*name;

	parent_path = NULL;
	if (parent)
		parent_name = ft_strdup(((t_data *)parent->content)->name);
	name = ft_strdup(((t_data *)l_args->content)->name);
	if (parent && (!ft_strequ(parent_name, name)))
	{
		parent_path = ft_strjoin(parent_name, name);
		name = ft_strjoin(parent_path, "/");
	}
	else
		name = ft_strjoin(name, "/");
	free(((t_data *)l_args->content)->name);
	((t_data *)l_args->content)->name = name;
	if (parent)
		free(parent_name);
	free(parent_path);
	return (l_args);
	
}

void				ls_perror(const char *path, int do_exit)
{
	char			*message;

	message = ft_strjoin("ft_ls: ", path);
	perror(message);
	if (do_exit == 1)
		exit(ERROR);
}

void				ls_usage(void)
{
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
	exit(ERROR);
}
