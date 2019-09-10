/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:26:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/10 15:55:38 by pforciol         ###   ########.fr       */
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
		{
			ls_print_dir(l_args, d_entries, opt);
		}
		d_entries = d_entries->next;
	}
	lst_clear(&d_entries);
}

static void			ls_print_total(t_list *d_entries)
{
	blkcnt_t		total;
	char			*stotal;
	char			*blocks;

	total = 0;
	while (d_entries)
	{
		total += ((t_data *)d_entries->content)->stats.st_blocks;
		d_entries = d_entries->next;
	}
	stotal = ft_itoa(total);
	blocks = ft_strjoin("total ", stotal);
	ft_putendl(blocks);
	free(stotal);
	free(blocks);
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
		{
			ls_print_l((t_data *)d_entries->content,
							(t_data *)l_args->content, widths, opt);
			if (d_entries->next)
				ft_putchar('\n');
		}
		else if (opt->one)
		{
			ls_print_w_color(((t_data *)d_entries->content)->name,
				((t_data *)d_entries->content)->stats.st_mode);
			if (d_entries->next)
				ft_putchar('\n');
		}
		else
		{
			ls_print_w_color(((t_data *)d_entries->content)->name,
				((t_data *)d_entries->content)->stats.st_mode);
			ft_putstr("    ");
		}
		d_entries = d_entries->next;
	}
	d_entries = tmp;
	ft_putchar('\n');
	if (opt->rr)
		ls_print_recursively(d_entries, l_args, opt);
	lst_clear(&tmp);
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
