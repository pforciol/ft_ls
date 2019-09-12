/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/12 16:04:35 by pforciol         ###   ########.fr       */
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
