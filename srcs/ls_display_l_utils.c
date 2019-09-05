/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_l_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:31:00 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/05 18:46:00 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls_display_l.h"

char			*ls_permissions(mode_t mode, char *path)
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
		return ("  ");
}

void			ls_print_type(mode_t mode, t_data *entry, t_data *parent,
									unsigned int *w)
{
	char			*attribute;
	char			*path;

	path = ft_strjoin(parent ? parent->name : "", entry->name);
	ft_putchar(entry->mode);
	if ((attribute = ls_permissions(mode, path)))
	{
		ft_putstr(attribute);
		ls_add_spaces(w[0], ft_intlen(entry->stats.st_nlink), 0);
	}
}

void			ls_print_mtime(time_t mtime)
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

void			ls_print_name(t_data *entry, t_data *parent, mode_t mode)
{
	char			buf[1024];
	ssize_t			count;
	char			*path;

	if (S_ISLNK(mode))
	{
		ft_bzero(buf, sizeof(buf));
		if (parent)
			path = ft_strjoin(parent->name, ft_strjoin("/", entry->name));
		else
			path = ft_strdup(entry->name);
		count = readlink(path, buf, sizeof(buf));
		if (count < 0)
		{
			free(path);
			ls_perror(path, 1);
			exit(ERROR);
		}
		buf[count] = '\0';
		ls_print_w_color(entry->name, mode);
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
	else
	{
		ls_print_w_color(entry->name, mode);
	}
}

void			ls_print_uid_and_gid(t_data *ety, unsigned int *w, t_opt *opt)
{
	if (opt->g == 0)
	{
		if (getpwuid(ety->stats.st_uid))
		{
			ft_putstr(getpwuid(ety->stats.st_uid)->pw_name);
			ls_add_spaces(w[1], ft_strlen(getpwuid(ety->stats.st_uid)->pw_name), 1);
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
