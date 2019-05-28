/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/28 16:21:53 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_data			*ft_getdata(t_data *data, char *path)
{
	struct stat		*p_stat;
	
	if(!(p_stat = malloc(sizeof(struct stat))))
		exit(ERROR);
	if(!(data = malloc(sizeof(t_data))))
		exit(ERROR);
	if (lstat(path, p_stat) != 0)
	{
		ft_perror(path, 0);
		free(data);
		return (NULL);
	}
	data->is_dir = S_ISDIR(p_stat->st_mode) == 1 ? 1 : 0;
	data->name = path;
	return(data);
}

t_list				*ft_getarg(char *arg, t_list *l_args, t_opt *opt)
{
	t_data			*data;
	DIR				*dir;

	data = NULL;
	if ((data = ft_getdata(data, arg)) != NULL)
	{
		lst_append(&l_args, lst_create(data, sizeof(data)));
		if (opt->ur == 1 && data->is_dir == 1)
		{
			dir = opendir(data->name);
			//TODO : OPENDIR, LIST DIR INTO char**, add them to list
	return (l_args);
}
