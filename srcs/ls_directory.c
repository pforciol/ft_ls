/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:55:26 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/12 16:04:28 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_list				*ls_getfile(char *parent_name, char *name, t_list *l_args)
{
	t_data			*data;
	char			*full_name;

	if (!(full_name = ft_strjoin(parent_name, name)))
		ls_error(NULL, MEM_ERROR);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ls_error(NULL, MEM_ERROR);
	lstat(full_name, &data->stats);
	if (data != NULL)
	{
		if (!(data->name = ft_strdup(name)))
			ls_error(NULL, MEM_ERROR);
		data->mode = ls_get_mode(data->stats.st_mode);
		lst_append(&l_args, lst_create(data, sizeof(t_data)));
	}
	free(full_name);
	return (l_args);
}

static t_list		*ls_readdir(DIR *dir, t_list *l_args, t_opt *opt)
{
	struct dirent	*file;
	t_list			*entries;

	entries = NULL;
	while ((file = readdir(dir)))
	{
		if (opt->a || file->d_name[0] != '.')
		{
			entries = ls_getfile(((t_data *)l_args->content)->name,
									file->d_name, entries);
		}
	}
	return (entries);
}

t_list				*ls_opendir(t_list *parent, t_list *l_args, t_opt *opt)
{
	DIR				*dir;
	t_list			*entries;
	char			*name;

	entries = NULL;
	if (!(name = ft_strdup(((t_data *)l_args->content)->name)))
		ls_error(NULL, MEM_ERROR);
	l_args = ls_set_parent(parent, l_args);
	dir = opendir(((t_data *)l_args->content)->name);
	if (!dir)
	{
		ls_error(name, ERRNO_ERROR);
		free(name);
		return (NULL);
	}
	free(name);
	entries = ls_readdir(dir, l_args, opt);
	closedir(dir);
	return (entries);
}
