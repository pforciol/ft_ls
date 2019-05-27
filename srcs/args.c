/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/27 12:07:17 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list				*ft_getargs(const char *argv[], int argc, t_opt *opt)
{
	t_data			*data;
	t_list			*l_args;
	int				i;
	int				j;

	l_args = NULL;
	i = opt->nb_opt + 1;
	j = 0;
	while (argv[i] != NULL && i < argc)
	{
		data->name = argv[i];
		lst_append(&l_args, lst_create(data, sizeof(data)));
		i++;
		j++;
	}
	return (l_args);
}
