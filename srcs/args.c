/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/12 12:28:44 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_data		*ft_getdata(t_data *data, char *path, struct stat *p_stat)
{
	if (!(data = malloc(sizeof(t_data))))
		exit(ERROR);
	data->name = path;
	data->mode = p_stat->st_mode;
	data->n_link = p_stat->st_nlink;
	data->uid = p_stat->st_uid;
	data->gid = p_stat->st_gid;
	data->size = p_stat->st_size;
	data->rdev = p_stat->st_rdev;
	data->time = p_stat->st_mtimespec.tv_sec;
	data->ntime = p_stat->st_mtimespec.tv_nsec;
	data->blocks = p_stat->st_blocks;
	return (data);
}

t_list				*ft_getarg(char *arg, t_list *l_args, t_opt *opt)
{
	t_data			*data;
	struct stat		p_stat;

	(void)opt;
	data = NULL;
	if (lstat(arg, &p_stat) != 0)
		ft_perror(arg, 0);
	else if ((data = ft_getdata(data, arg, &p_stat)) != NULL)
		lst_append(&l_args, lst_create(data, sizeof(data)));
	return (l_args);
}
