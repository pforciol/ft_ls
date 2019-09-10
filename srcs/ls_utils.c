/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:17:15 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/10 16:42:09 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls_utils.h"

void				ls_get_col_widths(t_list *l_args, unsigned int *w, int i)
{
	t_data			*tmp;

	ft_bzero(w, sizeof(int) * 7);
	while (l_args)
	{
		tmp = (t_data *)l_args->content;
		if (!(S_ISDIR(tmp->stats.st_mode) && i == 1))
		{
			w[0] = MAX(ft_intlen(tmp->stats.st_nlink), (int)w[0]);
			w[1] = MAX(getpwuid(tmp->stats.st_uid) ?
						ft_strlen(getpwuid(tmp->stats.st_uid)->pw_name)
							: ft_strlen(ft_itoa(tmp->stats.st_uid)), w[1]);
			w[2] = MAX(getgrgid(tmp->stats.st_gid) ?
						ft_strlen(getgrgid(tmp->stats.st_gid)->gr_name)
							: ft_strlen(ft_itoa(tmp->stats.st_gid)), w[2]);
			w[3] = MAX(ft_intlen(tmp->stats.st_size), (int)w[3]);
			w[4] = MAX(ft_intlen(major(tmp->stats.st_rdev)), (int)w[4]);
			w[5] = MAX(ft_intlen(minor(tmp->stats.st_rdev)), (int)w[5]);
			w[6] = S_ISBLK(tmp->stats.st_mode)
									|| S_ISCHR(tmp->stats.st_mode) ? 1 : 0;
		}
		l_args = l_args->next;
	}
}

t_list				*ls_set_parent(t_list *prt, t_list *l_args)
{
	char		*prt_path;
	char		*prt_name;
	char		*name;

	prt_path = NULL;
	name = ft_strdup(((t_data *)l_args->content)->name);
	((t_data *)l_args->content)->hasparent = prt ? 1 : 0;
	if (prt)
	{
		prt_name = ft_strdup(((t_data *)prt->content)->name);
		if ((!ft_strequ(prt_name, name)))
		{
			prt_path = ft_strjoin(prt_name, name);
			free(name);
			name = ft_strjoin(prt_path, ft_strequ(prt_path, "/") ? "" : "/");
		}
		ft_putchar('\n');
		ft_putnstr(name, ft_strlen(name) - 1);
		ft_putendl(":");
		free(prt_name);
	}
	else if (!(ft_strequ(name, "/")))
	{
		free(name);
		name = ft_strjoin(name, "/");
	}
	free(((t_data *)l_args->content)->name);
	((t_data *)l_args->content)->name = ft_strdup(name);
	free(name);
	free(prt_path);
	return (l_args);
}

void				ls_perror(const char *path, int do_exit)
{
	char			*message;

	message = ft_strjoin("ft_ls: ", path);
	perror(message);
	free(message);
	if (do_exit == 1)
		exit(ERROR);
}

void				ls_usage(void)
{
	ft_putendl("usage: ft_ls [-Radfglrt1] [file ...]");
	exit(ERROR);
}

void				ls_add_spaces(int width, int len, int sp)
{
	int				i;

	i = 0;
	while (i + len < width)
	{
		ft_putchar(' ');
		i++;
	}
	if (sp == 1)
		ft_putstr("  ");
}
