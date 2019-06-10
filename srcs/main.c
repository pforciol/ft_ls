/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:41:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/10 16:58:17 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list				*ls_init_list(char **args, int nb_args, t_opt *opt)
{
	t_list			*l_args;
	int				i;
	
	l_args = NULL;
	if (nb_args == 0)
		ft_getarg(".", l_args, opt);
	else if (!(nb_args == opt->nb_opt + 1))
	{
		i = opt->nb_opt + 1;
		while (args[i] != NULL && i < args)
		{
			l_args = ft_getarg(args[i], l_args, opt);
			i++;
		}
		l_args = ls_sort(opt, l_args, nb_args);
	}
	return (l_args);
}

int					main(int argc, char *argv[])
{
	t_list			*l_args;
	t_opt			*opt;
	int				i;

	opt = ft_get_opts(argv, argc);
	l_args = NULL;
	l_args = ls_init_list((char **)argv, argc - 1 - opt->nb_opt, opt);
	debug(opt, argc, l_args);
	return (0);
}
