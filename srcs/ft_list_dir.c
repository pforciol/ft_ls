/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:42:16 by pforciol          #+#    #+#             */
/*   Updated: 2019/04/17 12:57:29 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_perror(void)
{
	perror("Error");
}

int					main(int argc, char const *argv[])
{
	DIR				*dirp;
	const char		*path;
	struct dirent	*dir;

	(void)argc;
	path = ".";
	if (argv[1] != NULL)
		path = argv[1];
	if ((dirp = opendir(path)) == NULL)
		ft_perror();
	while ((dir = readdir(dirp)) != NULL)
	{
		ft_putendl(dir->d_name);
	}
	closedir(dirp);
	return (0);
}
