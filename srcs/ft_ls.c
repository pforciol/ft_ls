/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:26:10 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/10 17:10:58 by pforciol         ###   ########.fr       */
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
	if (valid_args == 0 && argc == opt->nb_opt + 1)
	{
		l_args = ls_getarg(".", l_args, &valid_args);
	}
	return (l_args);
}

int					main(int argc, char *argv[])
{
	t_list			*l_args;
	t_opt			*opt;

	opt = ls_get_opts(argv, argc);
	l_args = ls_init_list(argc, argv, opt);
	ls_process(l_args, opt, argc);
	free(opt);
	lst_clear(&l_args);
	//while (1);
	return (0);
}
