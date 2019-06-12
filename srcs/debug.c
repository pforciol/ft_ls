/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:23:01 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/12 10:25:05 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			see_options(t_opt *opt)
{
	ft_putstr("Enabled options : ");
	if (opt->ur == 1)
		ft_putchar('R');
	if (opt->la == 1)
		ft_putchar('a');
	if (opt->ll == 1)
		ft_putchar('l');
	if (opt->lr == 1)
		ft_putchar('r');
	if (opt->lt == 1)
		ft_putchar('t');
	if (opt->ur == 0 && opt->la == 0 && opt->ll == 0 && opt->lr == 0 && opt->lt == 0)
		ft_putstr("no options");
	ft_putchar('\n');
}

static void			args_info(t_opt *opt, int argc)
{
	if (!(argc == opt->nb_opt + 1))
	{
		ft_putstr("Index of first arg : ");
		ft_putnbr(opt->nb_opt + 1);
		ft_putchar('\n');
		ft_putstr("Count of args (no options) : ");
		ft_putnbr(argc - 1 - opt->nb_opt);
		ft_putchar('\n');
	}
	else if (argc == opt->nb_opt + 1)
		ft_putstr("No args specified, \".\" path set\n");
}

static void			print_args(t_list *l_args)
{
	int				i;
	char			*color;

	i = 0;
	color = "\033[0m";
	ft_putstr("List of all the args : ");
	while (l_args != NULL)
	{
		ft_putstr(ft_strjoin(ft_strjoin("[ ", ((t_data *)l_args->content)->name), " ] \033[0m"));
		l_args = l_args->next;
		i++;
	}
	ft_putchar('\n');
}

void				debug(t_opt *opt, int argc, t_list *l_args)
{
	see_options(opt);
	args_info(opt, argc);
	print_args(l_args);
}
