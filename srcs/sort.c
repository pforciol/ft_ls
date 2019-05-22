/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:20:46 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/22 15:15:09 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			sort_lexically(t_opt *opt, char *args[], int argc)
{
	int				i;
	char			*tmp;

	i = 0;
	while (args[i] != NULL && i < (argc - 2 - opt->nb_opt))
	{
		if (ft_strcmp(args[i], args[i + 1]) > 0)
		{
			tmp = args[i];
			args[i] = args[i + 1];
			args[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

char				**ls_sort(t_opt *opt, char *args[], int argc)
{
	if (opt->nb_opt == 0)
		sort_lexically(opt, args, argc);
	return (args);
}
