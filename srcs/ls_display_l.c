/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:28:45 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:08 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/ls_display_l.h"

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
