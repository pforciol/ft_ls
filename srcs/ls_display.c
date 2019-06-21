/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:26:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/21 15:53:28 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ls_print_dir(t_list *parent, t_list *l_args, t_opt *opt)
{
	t_list			*d_entries;
	t_list			*tmp;
	unsigned int	widths[7];

	if (!(d_entries = ls_opendir(parent, l_args, opt)))
		return ;
	if (opt->l)
		ft_putendl("total xx");
		//ls_print_total(d_entries);
	ls_lst_sort(opt, d_entries);
	tmp = d_entries;
	ls_get_columns_widths(d_entries, widths);
	while (d_entries)
	{
		if (opt->l)
			ft_putendl(ft_strjoin("Print -l of ", ((t_data *)d_entries->content)->name));
			//ls_print_l((t_data *)d_entries->content, (t_data *)l_args->content, widths);
		else
			ft_putendl(((t_data *)d_entries->content)->name);
		d_entries = d_entries->next;
	}
	d_entries = tmp;
	if (opt->rr)
		ft_putendl("NEED TO DO -R");
		//DO -R

		//TODO: HERE
}
