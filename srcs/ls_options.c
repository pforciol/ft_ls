/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:06:24 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/17 15:09:43 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ls_valid_opt(char c)
{
	if (ft_strchr("Ralrt", (int)c) == NULL || c == '\0')
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(c);
		ft_putchar('\n');
		ls_usage();
	}
}

static int			ls_set_opts(char *arg, t_opt *opt)
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
		ls_valid_opt(arg[i]);
		opt->rr = (arg[i] == 'R' ? 1 : opt->rr);
		opt->a = (arg[i] == 'a' ? 1 : opt->a);
		opt->l = (arg[i] == 'l' ? 1 : opt->l);
		opt->r = (arg[i] == 'r' ? 1 : opt->r);
		opt->t = (arg[i] == 't' ? 1 : opt->t);
		i++;
	}
	return (1);
}

static t_opt		*ls_init_opts(void)
{
	t_opt			*opt;

	if (!(opt = malloc(sizeof(t_opt))))
		exit(ERROR);
	opt->rr = 0;
	opt->a = 0;
	opt->l = 0;
	opt->r = 0;
	opt->t = 0;
	opt->nb_opt = 0;
	return (opt);
}

t_opt				*ls_get_opts(char *argv[], int argc)
{
	int				i;
	t_opt			*opt;

	opt = ls_init_opts();
	i = 1;
	while (i <= argc - 1)
	{
		if (ls_set_opts(argv[i], opt) == 0)
			return (opt);
		opt->nb_opt++;
		i++;
	}
	return (opt);
}