/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:41:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/28 15:07:12 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char *argv[])
{
	t_list			*l_args;
	t_opt			*opt;
	int				i;

	opt = ft_get_opts(argv, argc);
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
	debug(opt, argc, l_args);
	return (0);
}
