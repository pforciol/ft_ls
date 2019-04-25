/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:42:16 by pforciol          #+#    #+#             */
/*   Updated: 2019/04/25 17:17:20 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char const *argv[])
{
	DIR				*dir_ptr;
	const char		*path;
	struct dirent	*dir;

	(void)argc;
	path = ".";
	if (argv[1] != NULL)
		path = argv[1];
	if ((dir_ptr = opendir(path)) == NULL)
		ft_perror(path);
	else
	{
		while ((dir = readdir(dir_ptr)) != NULL)
		{
			ft_putendl(dir->d_name);
		}
		closedir(dir_ptr);
	}
	return (0);
}
