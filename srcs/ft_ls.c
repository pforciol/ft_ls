/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:26:10 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/21 12:30:45 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_list		*ls_init_list(int argc, char *argv[], t_opt *opt)
{
	t_list			*l_args;
	int				valid_args;
	int				i;

	l_args = NULL;
	valid_args = 0;
	if (!(argc == opt->nb_opt + 1))
	{
		i = opt->nb_opt + 1;
		while (argv[i] != NULL && i < argc)
		{
			l_args = ls_getarg(argv[i], l_args, &valid_args);
			i++;
		}
		if (argc > 2)
			l_args = ls_lst_sort(opt, l_args);
	}
	if (valid_args == 0)
	{
		l_args = ls_getarg(".", l_args, &valid_args);
	}
	return (l_args);
}

int					main(int argc, char *argv[])
{
	t_list			*l_args;
	t_opt			*opt;
	int				list_len;

	opt = ls_get_opts(argv, argc);
	l_args = ls_init_list(argc, argv, opt);
	list_len = get_lst_size(l_args);
	ls_process(l_args, opt, list_len);
	debug(opt, argc, l_args);
	return (0);
}
