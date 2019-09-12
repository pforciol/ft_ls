/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:01:08 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/12 20:14:28 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ls_process_dir(t_list *l_args, t_opt *opt, t_list *before,
										int ac)
{
	if (before || ac - 1 - opt->nb_opt >= 2)
	{
		if (before)
			ft_putstr("\n\n");
		ft_putstr(((t_data *)l_args->content)->name);
		ft_putendl(":");
	}
	ls_print_dir(NULL, l_args, opt);
}

static t_list		*ls_process_file(t_list *l_args, t_opt *opt,
												unsigned int *widths)
{
	if (opt->l)
	{
		ls_print_l((t_data *)l_args->content, NULL, widths, opt);
		if (l_args->next)
			ft_putchar('\n');
	}
	else if (opt->one)
	{
		ls_print_w_color(((t_data *)l_args->content)->name,
				((t_data *)l_args->content)->stats.st_mode);
		if (l_args->next)
			ft_putchar('\n');
	}
	else
	{
		ls_print_w_color(((t_data *)l_args->content)->name,
				((t_data *)l_args->content)->stats.st_mode);
		ft_putstr("    ");
	}
	return (l_args);
}

static int			ls_pre_process(t_list *l_args, t_list *before, t_opt *opt,
										unsigned int *widths)
{
	int				file;
	DIR				*tmp_dir;

	file = 0;
	while (l_args)
	{
		tmp_dir = NULL;
		if ((S_ISDIR(((t_data *)l_args->content)->stats.st_mode)
					|| ((((t_data *)l_args->content)->mode == 'l')
					&& (tmp_dir = opendir(((t_data *)l_args->content)->name))
					&& opt->l == 0)) && opt->d == 0)
			((t_data *)l_args->content)->is_dir = 1;
		else
		{
			before = ls_process_file(l_args, opt, widths);
			file++;
		}
		l_args = l_args->next;
		if (tmp_dir)
			closedir(tmp_dir);
	}
	if (file != 0 || get_lst_size(l_args) - 1 - opt->nb_opt != 0)
		ft_putchar('\n');
	return (file);
}

void				ls_process(t_list *l_args, t_opt *opt, int ac)
{
	unsigned int	widths[7];
	t_list			*before;
	t_list			*start;
	int				file;

	before = NULL;
	start = l_args;
	file = 0;
	if (opt->l)
		ls_get_col_widths(l_args, widths, 1);
	file += ls_pre_process(l_args, before, opt, widths);
	l_args = start;
	ft_putstr((file > 1 && opt->l == 0 && before) ? "\n\n" : "\0");
	if (opt->d == 0)
	{
		while (l_args)
		{
			if (((t_data *)l_args->content)->is_dir == 1)
				ls_process_dir(l_args, opt, before, ac);
			before = l_args;
			l_args = l_args->next;
		}
	}
}
