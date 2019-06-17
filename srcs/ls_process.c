/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:01:08 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/17 15:25:47 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ls_process_dir(t_list *l_args, t_opt *opt, t_list *before,
									int list_len)
{
	if (!ft_strequ(".", ((t_data *)l_args->content)->name))
	{
		if (before)
			ft_putstr("\n");
		if (list_len > 1)
			ft_putendl(((t_data *)l_args->content)->name);
	}
	ls_print_dir_content(NULL, l_args, opt);
}

void				ls_process(t_list *l_args, t_opt *opt, int list_len)
{
	unsigned int	widths[7];
	t_list			*before;
	(void)list_len;
	(void)opt;

	before = NULL;
	ls_get_columns_widths(l_args, widths);
	while (l_args)
	{
		if (S_ISDIR(((t_data *)l_args->content)->mode))
			ls_process_dir(l_args, opt, before, list_len);
		else
		{
			if (opt->l)
				ls_print_l((t_data *)l_args->content, NULL, widths);
			else
				ft_putendl(((t_data *)l_args->content)->name);
		}
		before = l_args;
		l_args = l_args->next;
	}
}

