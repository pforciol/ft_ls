/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_names.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:37:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/12 17:11:38 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ls_has_parent(char **prt_path, char **name, t_list *prt)
{
	char		*prt_name;

	if (!(prt_name = ft_strdup(((t_data *)prt->content)->name)))
		ls_error(NULL, MEM_ERROR);
	if ((!ft_strequ(prt_name, *name)))
	{
		if (!(*prt_path = ft_strjoin(prt_name, *name)))
			ls_error(NULL, MEM_ERROR);
		free(*name);
		if (!(*name = ft_strjoin(*prt_path,
									ft_strequ(*prt_path, "/") ? "" : "/")))
			ls_error(NULL, MEM_ERROR);
	}
	ft_putchar('\n');
	ft_putnstr(*name, ft_strlen(*name) - 1);
	ft_putendl(":");
	free(prt_name);
}

t_list			*ls_set_parent(t_list *prt, t_list *l_args)
{
	char		*prt_path;
	char		*name;

	prt_path = NULL;
	if (!(name = ft_strdup(((t_data *)l_args->content)->name)))
		ls_error(NULL, MEM_ERROR);
	if (prt)
	{
		ls_has_parent(&prt_path, &name, prt);
	}
	else if (!(ft_strequ(name, "/")))
	{
		free(name);
		if (!(name = ft_strjoin(name, "/")))
			ls_error(NULL, MEM_ERROR);
	}
	free(((t_data *)l_args->content)->name);
	if (!(((t_data *)l_args->content)->name = ft_strdup(name)))
		ls_error(NULL, MEM_ERROR);
	free(name);
	free(prt_path);
	return (l_args);
}

static char		*ls_get_link(t_data *parent, t_data *entry)
{
	char		*path;
	char		*path2;

	if (parent)
	{
		if (!(path2 = ft_strjoin("/", entry->name)))
			ls_error(NULL, MEM_ERROR);
		if (!(path = ft_strjoin(parent->name, path2)))
			ls_error(NULL, MEM_ERROR);
		free(path2);
	}
	else
	{
		if (!(path = ft_strdup(entry->name)))
			ls_error(NULL, MEM_ERROR);
	}
	return (path);
}

void			ls_print_name(t_data *entry, t_data *parent, mode_t mode)
{
	char		buf[1024];
	ssize_t		count;
	char		*path;

	if (S_ISLNK(mode))
	{
		ft_bzero(buf, sizeof(buf));
		path = ls_get_link(parent, entry);
		count = readlink(path, buf, sizeof(buf));
		if (count < 0)
		{
			ls_error(path, ERRNO_ERROR);
			free(path);
		}
		free(path);
		buf[count] = '\0';
		ls_print_w_color(entry->name, mode);
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
	else
		ls_print_w_color(entry->name, mode);
}
