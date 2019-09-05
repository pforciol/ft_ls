/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_args_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/05 18:42:51 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				ls_get_mode(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFREG)
		return ('-');
	else if ((mode & S_IFMT) == S_IFIFO)
		return ('f');
	else if ((mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		return ('s');
	return (0);
}

void				ls_print_w_color(char *name, mode_t mode)
{
	if ((mode & S_IFMT) == S_IFDIR)
		ft_putcolor(name, CYAN, NULL, "BOLD");
	else if ((mode & S_IFMT) == S_IFLNK)
		ft_putcolor(name, PURPLE, NULL, NULL);
	else if ((mode & S_IFMT) == S_IFBLK)
		ft_putcolor(name, BLUE, BG_CYAN, NULL);
	else if ((mode & S_IFMT) == S_IFCHR)
		ft_putcolor(name, BLUE, BG_YELLOW, NULL);
	else if ((mode & S_IFMT) == S_IFSOCK)
		ft_putcolor(name, WHITE, NULL, NULL);
	else if ((mode & S_IFMT) == S_IFIFO)
		ft_putcolor(name, YELLOW, NULL, NULL);
	else if (mode & S_IXUSR || mode & S_IXGRP || mode & S_IXOTH)
		ft_putcolor(name, RED, NULL, NULL);
	else
		ft_putstr(name);
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
		lst_append(&l_args, lst_create(data, sizeof(t_data)));
		(*v_a)++;
	}
	return (l_args);
}
