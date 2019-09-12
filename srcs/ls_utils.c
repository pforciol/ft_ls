/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:17:15 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/12 16:04:19 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

void				ls_error(const char *path, int error)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (error == ERRNO_ERROR)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
	else if (error == MEM_ERROR)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
}

void				ls_usage(void)
{
	ft_putendl_fd("usage: ft_ls [-Radfglrt1] [file ...]", 2);
	exit(EXIT_FAILURE);
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

void				ft_putcolor(char *str, char *color, char *bg, char *format)
{
	if (color != NULL)
		ft_putstr(color);
	if (bg != NULL)
		ft_putstr(bg);
	if (format != NULL)
	{
		if (ft_strstr(format, "BOLD") != 0)
			ft_putstr(BOLD);
	}
	ft_putstr(str);
	ft_putstr(RESET);
}
