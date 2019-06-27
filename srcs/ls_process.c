/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:01:08 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/27 11:31:43 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ls_process_dir(t_list *l_args, t_opt *opt, t_list *before,
									int list_len, int ac)
{
	(void)before;
	if (before)
		ft_putstr("\n");
	if (list_len >= 2 || ac > 2)
		ft_putendl(ft_strjoin(((t_data *)l_args->content)->name, ":"));
	ls_print_dir(NULL, l_args, opt);
}

void				ls_process(t_list *l_args, t_opt *opt, int lst_len, int ac)
{
	unsigned int	widths[7];
	t_list			*before;
	t_list			*start;

	before = NULL;
	start = l_args;
	ls_get_columns_widths(l_args, widths);
	while (l_args)
	{
		if (S_ISDIR(((t_data *)l_args->content)->stats.st_mode))
			((t_data *)l_args->content)->is_dir = 1;
		else
		{
			if (opt->l)
				ft_putendl(ft_strjoin("Print -l of ", ((t_data *)l_args->content)->name));
				//ls_print_l((t_data *)l_args->content, NULL, widths);
			else
				ft_putendl(((t_data *)l_args->content)->name);
			before = l_args;
		}
		l_args = l_args->next;
	}
	l_args = start;
	while (l_args)
	{
		if (((t_data *)l_args->content)->is_dir == 1)
			ls_process_dir(l_args, opt, before, lst_len, ac);
		before = l_args;
		l_args = l_args->next;
	}
}

