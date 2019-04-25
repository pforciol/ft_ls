/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:16:30 by pforciol          #+#    #+#             */
/*   Updated: 2019/04/25 18:35:15 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void				assign_file_data(t_file *file, struct stat *restrict buf)
{
	ft_strmode(buf->st_mode, file->modes);
}

int					main(int argc, char *argv[])
{
	struct stat		buf;
	const char		*path;
	t_file			*file;

	file = NULL;

	(void)argc;
	if (argv[1] == NULL)
	{
		ft_putendl("This program doesn't list files...");
		exit(ERROR);
	}
	path = argv[1];
	if (stat(path, &buf) == -1)
		ft_perror(path);
	else
	{
		assign_file_data(file, &buf);
		//file->name = (char *)path;
		//ft_putendl(file->name);
		//ft_putendl(file->type);
		ft_putendl(file->modes);
		// ft_putendl(ft_itoa(file->links));
		// ft_putendl(file->owner);
		// ft_putendl(file->group);
		// ft_putendl(ft_itoa(file->size));
		// ft_putendl(file->last_edit);
	}
	return (0);
}
