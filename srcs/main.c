/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:26:10 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/12 12:56:10 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_list		*ls_init_list(int argc, char *argv[], t_opt *opt)
{
	t_list			*l_args;
	int				i;

	l_args = NULL;
	if (!(argc == opt->nb_opt + 1))
	{
		i = opt->nb_opt + 1;
		while (argv[i] != NULL && i < argc)
		{
			l_args = ft_getarg(argv[i], l_args, opt);
			i++;
		}
		l_args = ls_sort(opt, l_args, argc);
	}
	else if (argc == opt->nb_opt + 1)
	{
		l_args = ft_getarg(".", l_args, opt);
	}
	return (l_args);
}

int					main(int argc, char *argv[])
{
	t_list			*l_args;
	t_opt			*opt;

	opt = ft_get_opts(argv, argc);
	l_args = ls_init_list(argc, argv, opt);
	debug(opt, argc, l_args);
	return (0);
}
