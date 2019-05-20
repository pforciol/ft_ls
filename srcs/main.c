/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:41:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/20 14:37:22 by pforciol         ###   ########.fr       */
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

int					ft_ls(t_opt options, const char *path)
{
	struct stat		*path_stat;
	
	if (lstat(path, path_stat) != -1)
	{
		if ((path_stat->st_mode & S_IFMT) == S_IFREG)
		{
			if (options->)
		}
	}
}

int					main(int argc, char const *argv[])
{
	DIR				*dir_ptr;
	const char		*path;
	t_opt 			options;
	
}
