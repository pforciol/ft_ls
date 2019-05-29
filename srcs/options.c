/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:06:24 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/29 10:54:09 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ft_valid_opt(char c)
{
	if (ft_strchr("Ralrt", (int)c) == NULL || c == '\0')
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(c);
		ft_putchar('\n');
		ft_usage();
	}
}

static int			ft_set_opts(char *arg, t_opt *opt)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(arg);
	if (arg[i] == '-' && i == 0 && len > 1)
		i++;
	else
		return (0);
	while (arg[i] != '\0')
	{
		ft_valid_opt(arg[i]);
		opt->ur = (arg[i] == 'R' ? 1 : opt->ur);
		opt->la = (arg[i] == 'a' ? 1 : opt->la);
		opt->ll = (arg[i] == 'l' ? 1 : opt->ll);
		opt->lr = (arg[i] == 'r' ? 1 : opt->lr);
		opt->lt = (arg[i] == 't' ? 1 : opt->lt);
		i++;
	}
	return (1);
}

static t_opt		*ft_init_opts(void)
{
	t_opt			*opt;

	if (!(opt = malloc(sizeof(t_opt))))
		exit(ERROR);
	opt->ur = 0;
	opt->la = 0;
	opt->ll = 0;
	opt->lr = 0;
	opt->lt = 0;
	opt->nb_opt = 0;
	return (opt);
}

t_opt				*ft_get_opts(char *argv[], int argc)
{
	int				i;
	t_opt			*opt;

	opt = ft_init_opts();
	i = 1;
	while (i <= argc - 1)
	{
		if (ft_set_opts(argv[i], opt) == 0)
			return (opt);
		opt->nb_opt++;
		i++;
	}
	return (opt);
}
