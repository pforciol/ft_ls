/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:41:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/22 14:38:06 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char const *argv[])
{
	char			**args;
	t_opt			*opt;

	opt = ft_get_opts(argv, argc);
	args = NULL;
	if (!(argc == opt->nb_opt))
	{
		args = ft_cpynargs(argv, argc, opt);
		args = ls_sort(opt, args, argc);
	}
	debug(opt, argc, args);
	return (0);
}
