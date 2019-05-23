/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:20:46 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/23 10:55:52 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			sort_lexically(t_opt *opt, char *args[], int argc, int r)
{
	int				i;
	char			*tmp;

	i = 0;
	while (args[i] != NULL && i < (argc - 2 - opt->nb_opt))
	{
		if (r == 0 && ft_strcmp(args[i], args[i + 1]) > 0)
		{
			tmp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = tmp;
			i = -1;
		}
		else if (r > 0 && ft_strcmp(args[i], args[i + 1]) < 0)
		{
			tmp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	args[++i] = "\0";
}

char				**ls_sort(t_opt *opt, char *args[], int argc)
{
	if (opt->nb_opt == 0 || opt->lr == 0)
		sort_lexically(opt, args, argc, 0);
	else if (opt->lr == 1 && opt->lt == 0)
		sort_lexically(opt, args, argc, 1);
	return (args);
}
