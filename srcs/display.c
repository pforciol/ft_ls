/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:35:16 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/11 10:09:35 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ls_display(t_list *begin, t_opt opt, int first, int n)
{
	t_list			*l_args;
	t_data			*file;

	l_args = begin;
	file = NULL;
	if (opt.ur == 0 && first == 0)
		return (SUCCESS);
	while (l_args)
	{
		file = l_args->content;
		if (S_ISDIR(file->mode) && (first == 1 || (ft_strcmp(file->name, ".")
				&& ft_strcmp(file->name))))
	}
}
