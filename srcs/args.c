/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/27 18:27:10 by pforciol         ###   ########.fr       */
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

t_list				*ft_getargs(const char *args[], int argc, t_opt *opt)
{
	t_data			*data;
	t_list			*l_args;
	int				i;

	l_args = NULL;
	i = opt->nb_opt + 1;
	while (args[i] != NULL && i < argc)
	{
		data = NULL;
		if ((data = ft_getdata(data, (char *)args[i])) != NULL)
			lst_append(&l_args, lst_create(data, sizeof(data)));
		i++;
	}
	return (l_args);
}
