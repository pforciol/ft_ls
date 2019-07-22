/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_args_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/07/22 16:24:54 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				ls_get_mode(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((mode & S_IFMT) == S_IFIFO)
		ft_putchar('f');
	else if ((mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
}

t_list				*ls_getarg(char *arg, t_list *l_args, int *v_a)
{
	t_data			*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		exit(ERROR);
	if (lstat(arg, &data->stats) != 0)
		ls_perror(arg, 0);
	else if (data != NULL)
	{
		data->name = ft_strdup(arg);
		data->mode = ls_get_mode(data->stats.st_mode);
		// data->color = 
		lst_append(&l_args, lst_create(data, sizeof(t_data)));
		(*v_a)++;
	}
	return (l_args);
}
