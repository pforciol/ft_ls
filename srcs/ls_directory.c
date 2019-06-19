/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:55:26 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/19 14:25:40 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// static t_list			*ls_getfile(char *arg, t_list *l_args)
// {
// 	t_data			*data;

// 	if(!(data = (t_data *)malloc(sizeof(t_data))))
// 		exit(ERROR);
// 	lstat(arg, &data->stats
// 	data->name = ft_strdup(arg);
// 	lst_append(&l_args, lst_create(data, sizeof(t_data)));
// 	return (l_args);
// }


static t_list		*ls_readdir(DIR *dir, t_list *l_args, t_opt *opt)
{
	struct dirent	*file;
	t_data			*entry;
	t_list			*entries;

	entries = NULL;
	entry = NULL;
	while ((file = readdir(dir)))
	{
		if (opt->a || file->d_name[0] != '.')
		{
			entry->name = ft_strdup(file->d_name);
			lstat(ft_strjoin(((t_data *)l_args->content)->name, file->d_name),
									&entry->stats);
			lst_append(&entries, lst_create(entry, sizeof(t_data)));
		}
		file = readdir(dir);
	}
	return(entries);
}

t_list				*ls_opendir(t_list *parent, t_list *l_args, t_opt *opt)
{
	DIR				*dir;
	t_list			*entries;
	char			*name;

	entries = NULL;
	name = ft_strdup(((t_data *)l_args->content)->name);
	l_args = ls_append_parent(parent, l_args);
	dir = opendir(((t_data *)l_args->content)->name);
	if (!dir)
	{
		ls_perror(name, 0);
		return (NULL);
	}
	free(name);
	entries = ls_readdir(dir, l_args, opt);
	closedir(dir);
	return (entries);
}
