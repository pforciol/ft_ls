/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:26:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/07/18 17:23:51 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ls_print_recursively(t_list *d_entries, t_list *l_args,
											t_opt *opt)
{
	while (d_entries)
	{
		if (S_ISDIR(((t_data *)d_entries->content)->stats.st_mode) &&
				!ft_strequ(((t_data *)d_entries->content)->name, ".") &&
				!ft_strequ(((t_data *)d_entries->content)->name, ".."))
			ls_print_dir(l_args, d_entries, opt);
		d_entries = d_entries->next;
	}
}

static void			ls_print_total(t_list *d_entries)
{
	blkcnt_t		total;

	total = 0;
	while (d_entries)
	{
		total += ((t_data *)d_entries->content)->stats.st_blocks;
		d_entries = d_entries->next;
	}
	ft_putendl(ft_strjoin("total ", ft_itoa(total)));
}

void				ls_print_dir(t_list *parent, t_list *l_args, t_opt *opt)
{
	t_list			*d_entries;
	t_list			*tmp;
	unsigned int	widths[7];

	if (!(d_entries = ls_opendir(parent, l_args, opt)))
		return ;
	if (opt->l)
		ls_print_total(d_entries);
	ls_lst_sort(opt, d_entries);
	tmp = d_entries;
	ls_get_col_widths(d_entries, widths, 0);
	while (d_entries)
	{
		if (opt->l)
			ls_print_l((t_data *)d_entries->content, 
							(t_data *)l_args->content, widths);
		else
			ft_putendl(((t_data *)d_entries->content)->name);
		d_entries = d_entries->next;
	}
	d_entries = tmp;
	if (opt->rr)
		ls_print_recursively(d_entries, l_args, opt);
}
