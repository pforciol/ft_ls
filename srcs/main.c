/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:41:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/27 20:55:41 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char const *argv[])
{
	t_list			*l_args;
	t_opt			*opt;

	opt = ft_get_opts(argv, argc);
	l_args = NULL;
	if (!(argc == opt->nb_opt + 1))
	{
		l_args = ft_getargs(argv, argc, opt);
		l_args = ls_sort(opt, l_args, argc);
	}
	debug(opt, argc, l_args);
	return (0);
}
