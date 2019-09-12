/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:28:45 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/12 16:04:27 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*ls_permissions(mode_t mode, char *path)
{
	acl_t acl;

	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((mode & S_IXOTH) ? 'x' : '-');
	if ((listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
				&& !((mode & S_IFMT) == S_IFCHR || (mode & S_IFMT) == S_IFBLK))
		return ("@ ");
	else if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) != NULL)
	{
		acl_free(acl);
		return ("+ ");
	}
	else
	{
		acl_free(acl);
		return ("  ");
	}
}

static void			ls_print_type(mode_t mode, t_data *entry, t_data *parent,
									unsigned int *w)
{
	char			*attribute;
	char			*path;

	if (!(path = ft_strjoin(parent ? parent->name : "", entry->name)))
		ls_error(NULL, MEM_ERROR);
	ft_putchar(entry->mode);
	if ((attribute = ls_permissions(mode, path)))
	{
		ft_putstr(attribute);
		ls_add_spaces(w[0], ft_intlen(entry->stats.st_nlink), 0);
	}
	free(path);
}

static void			ls_print_mtime(time_t mtime)
{
	char			*full_time;
	int				start;
	int				end;
	int				i;
	time_t			current;

	current = time(NULL);
	full_time = ctime(&mtime);
	start = 4;
	end = 10;
	i = start;
	while (i >= start && i < end)
		ft_putchar(full_time[i++]);
	ft_putchar(' ');
	start = (mtime > current || mtime < current - 15552000) ? 20 : 11;
	end = (mtime > current || mtime < current - 15552000) ? 24 : 16;
	i = start;
	while (i >= start && i < end)
	{
		if (i == 20)
			ft_putchar(' ');
		ft_putchar(full_time[i++]);
	}
}

static void			ls_print_uid_and_gid(t_data *ety, unsigned int *w, t_opt *opt)
{
	if (opt->g == 0)
	{
		if (getpwuid(ety->stats.st_uid))
		{
			ft_putstr(getpwuid(ety->stats.st_uid)->pw_name);
			ls_add_spaces(w[1], ft_strlen(
									getpwuid(ety->stats.st_uid)->pw_name), 1);
		}
		else
		{
			ft_putnbr(ety->stats.st_uid);
			ls_add_spaces(w[1], ft_intlen(ety->stats.st_uid), 1);
		}
	}
	if (getgrgid(ety->stats.st_gid))
	{
		ft_putstr(getgrgid(ety->stats.st_gid)->gr_name);
		ls_add_spaces(w[2], ft_strlen(getgrgid(ety->stats.st_gid)->gr_name), 0);
	}
	else
	{
		ft_putnbr(ety->stats.st_gid);
		ls_add_spaces(w[2], ft_intlen(ety->stats.st_gid), 0);
	}
}

void				ls_print_l(t_data *entry, t_data *parent, unsigned int *w,
								t_opt *opt)
{
	ls_print_type(entry->stats.st_mode, entry, parent, w);
	ft_putnbr(entry->stats.st_nlink);
	ft_putchar(' ');
	ls_print_uid_and_gid(entry, w, opt);
	if (w[6] == 1)
	{
		ls_add_spaces(w[4], ft_intlen(entry->stats.st_rdev >> 24), 1);
		ft_putstr(ft_itoa(entry->stats.st_rdev >> 24));
		ft_putstr(", ");
		ls_add_spaces(w[5], ft_intlen(entry->stats.st_rdev & 0xFFFFFF), 0);
		ft_putnbr(entry->stats.st_rdev & 0xFFFFFF);
	}
	else
	{
		ls_add_spaces(w[3], ft_intlen(entry->stats.st_size), 1);
		ft_putnbr(entry->stats.st_size);
	}
	ft_putchar(' ');
	ls_print_mtime(entry->stats.st_mtime);
	ft_putchar(' ');
	ls_print_name(entry, parent, entry->stats.st_mode);
}
