/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_args_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:18 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/19 10:07:22 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list				*ls_getarg(char *arg, t_list *l_args, int *v_a)
{
	t_data			*data;

	if(!(data = (t_data *)malloc(sizeof(t_data))))
		exit(ERROR);
	if (lstat(arg, &data->stats) != 0)
		ls_perror(arg, 0);
	else if (data != NULL)
	{
		data->name = ft_strdup(arg);
		lst_append(&l_args, lst_create(data, sizeof(t_data)));
		(*v_a)++;
	}
	return (l_args);
}
