/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:28:45 by pforciol          #+#    #+#             */
/*   Updated: 2019/07/18 18:54:38 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ls_print_permissions(mode_t mode)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}

static void			ls_print_type(mode_t mode, t_data *entry, t_data *parent, 
									unsigned int *w)
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
	ls_print_permissions(mode);
	if (listxattr(ft_strjoin(parent ? parent->name : "", entry->name),
				NULL, 0, XATTR_NOFOLLOW) > 0
				&& !((mode & S_IFMT) == S_IFCHR || (mode & S_IFMT) == S_IFBLK))
	{
		ft_putstr("@ ");
		ls_add_spaces(w[0], ft_intlen(entry->stats.st_nlink), 0);
	}
	else
		ls_add_spaces(w[0], ft_intlen(entry->stats.st_nlink), 1);
}

/*
 *	For files with a time that is more than 6 months old or more than 1 hour
 *	into the future, the timestamp contains the year instead of the time of day.
*/

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

static void			ls_print_name(t_data *entry, t_data *parent, mode_t mode)
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
		ft_putstr(entry->name);
		ft_putstr(" -> ");
		ft_putendl(buf);
	}
	else
		ft_putendl(entry->name);
}

void				ls_print_l(t_data *entry, t_data *parent, unsigned int *w)
{
	ls_print_type(entry->stats.st_mode, entry, parent, w);
	ft_putnbr(entry->stats.st_nlink);
	ft_putchar(' ');
	if (getpwuid(entry->stats.st_uid))
	{
		ft_putstr(getpwuid(entry->stats.st_uid)->pw_name);
		ls_add_spaces(w[1], ft_strlen(getpwuid(entry->stats.st_uid)->pw_name), 1);
	}
	else
	{
		ft_putnbr(entry->stats.st_uid);
		ls_add_spaces(w[1], ft_intlen(entry->stats.st_uid), 1);
	}
	if (getgrgid(entry->stats.st_gid))
	{
		ft_putstr(getgrgid(entry->stats.st_gid)->gr_name);
		ls_add_spaces(w[2], ft_strlen(getgrgid(entry->stats.st_gid)->gr_name), 0);
	}
	else
	{
		ft_putnbr(entry->stats.st_gid);
		ls_add_spaces(w[2], ft_intlen(entry->stats.st_gid), 0);
	}
	if (w[6] == 1)
	{
		ls_add_spaces(w[4], ft_intlen(entry->stats.st_rdev >> 24), 1);
		ft_putstr(ft_strjoin(ft_itoa(entry->stats.st_rdev >> 24), ", "));
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

