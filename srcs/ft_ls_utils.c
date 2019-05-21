/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:17:15 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/21 15:32:19 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				ft_perror(const char *path)
{
	char			*message;

	message = ft_strjoin("ft_ls: ", path);
	perror(message);
	exit(ERROR);
}

void				ft_usage(void)
{
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
	exit(ERROR);
}
