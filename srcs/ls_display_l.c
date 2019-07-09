/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:28:45 by pforciol          #+#    #+#             */
/*   Updated: 2019/07/09 16:40:34 by pforciol         ###   ########.fr       */
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

static void			ls_print_type(mode_t mode)
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
}

void				ls_print_l(t_data *entry, t_data *parent, unsigned int *w)
{
	(void)parent;
	ls_print_type(entry->stats.st_mode);
	ls_add_spaces(w[0], ft_intlen(entry->stats.st_nlink));
	ft_putnbr(entry->stats.st_nlink);
	ft_putchar(' ');
	if (getpwuid(entry->stats.st_uid))
	{
		ft_putstr(getpwuid(entry->stats.st_uid)->pw_name);
		ls_add_spaces(w[1], ft_strlen(getpwuid(entry->stats.st_uid)->pw_name));
	}
	else
	{
		ft_putnbr(entry->stats.st_uid);
		ls_add_spaces(w[1], ft_intlen(entry->stats.st_uid));
	}
	if (getgrgid(entry->stats.st_gid))
	{
		ft_putstr(getgrgid(entry->stats.st_gid)->gr_name);
		ls_add_spaces(w[1], ft_strlen(getgrgid(entry->stats.st_gid)->gr_name));
	}
	else
	{
		ft_putnbr(entry->stats.st_gid);
		ls_add_spaces(w[1], ft_intlen(entry->stats.st_gid));
	}
	ls_add_spaces(w[3], ft_intlen(entry->stats.st_size));
	ft_putnbr(entry->stats.st_size);
	
	//WORK HERE
	ft_putchar('\n');
}

