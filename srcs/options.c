/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:06:24 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/21 17:22:16 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ft_valid_opt(char c)
{
	char			*options;

	options = "Ralrt";
	if (ft_strchr(options, (int)c) == NULL || c == '\0')
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(c);
		ft_putchar('\n');
		ft_usage();
	}
}

static int			ft_set_opts(const char *arg, t_opt *opt)
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
		opt->R = (arg[i] == 'R' ? 1 : opt->R);
		opt->a = (arg[i] == 'a' ? 1 : opt->a);
		opt->l = (arg[i] == 'l' ? 1 : opt->l);
		opt->r = (arg[i] == 'r' ? 1 : opt->r);
		opt->t = (arg[i] == 't' ? 1 : opt->t);
		i++;
	}
	return (1);
}

static t_opt		*ft_init_opts(void)
{
	t_opt			*opt;

	if (!(opt = malloc(sizeof(t_opt))))
		exit(ERROR);
	opt->R = 0;
	opt->a = 0;
	opt->l = 0;
	opt->r = 0;
	opt->t = 0;
	opt->nb_args = 0;
	return (opt);
}

t_opt				*ft_get_opts(const char *argv[], int argc)
{
	int				i;
	int				j;
	t_opt			*opt;

	opt = ft_init_opts();
	i = 1;
	while (i <= argc - 1)
	{
		opt->nb_args = i - 1;
		if (ft_set_opts(argv[i], opt) == 0)
			return (opt);
		i++;
	}
	return (opt);
}
