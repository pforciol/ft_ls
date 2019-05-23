/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:24:33 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/23 10:58:26 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_ls(t_opt *opt, char *args[])
{
	int				i;
	struct stat		*p_stat;

	i = 0;
	while (args[i] != NULL)
	{
		if (stat(args[i], &p_stat) != 0)
			return (0);
		return S_ISDIR(statbuf.st_mode);
}

}

int					ft_is_dir
