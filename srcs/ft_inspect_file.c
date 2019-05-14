/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:16:30 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/14 17:56:25 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			set_file_name(t_file *f_data, const char *path)
{
	int len;

	if (!(f_data = malloc(sizeof(t_file))))
		exit(ERROR);
	len = ft_strlen(ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 1 : path);
	if (!(f_data->name = malloc(sizeof(char *) * len + 1)))
		exit(ERROR);
	f_data->name = ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 1 : path;
}

static void			set_file_type(struct stat *f_stat, t_file *f_data)
{
	if (!(f_data->type = malloc(sizeof(char *) * 19)))
		exit(ERROR);
	if (S_ISREG(f_stat->st_mode))
		f_data->type = "Fichier\0";
	else if (S_ISDIR(f_stat->st_mode))
		f_data->type = "Répertoire\0";
	else if (S_ISLNK(f_stat->st_mode))
		f_data->type = "Lien Symbolique\0";
	else if (S_ISBLK(f_stat->st_mode))
		f_data->type = "Périphérique Block\0";
	else if (S_ISCHR(f_stat->st_mode))
		f_data->type = "Périphérique Char\0";
	else if (S_ISSOCK(f_stat->st_mode))
		f_data->type = "Socket\0";
	else if (S_ISFIFO(f_stat->st_mode))
		f_data->type = "FIFO\0";
	else
		f_data->type = "Fichier\0";
}

static t_file		*set_file_data(const char *path, struct stat *f_stat)
{
	t_file			*f_data;
	
	if (!(f_data = malloc(sizeof(t_file))))
		exit(ERROR);
	set_file_name(f_data, path);
	set_file_type(f_stat, f_data);

	return (f_data);
}

static void			print_file_data(const char *path, struct stat *f_stat)
{
	t_file			*f_data;

	f_data = set_file_data(path, f_stat);
	ft_putendl(ft_strjoin("Nom: ", f_data->name));
	ft_putendl(f_data->type);
}

int					main(int argc, char const *argv[])
{
	const char		*path;
	struct stat		*f_stat;

	path = argv[1];
	if (path == NULL && argc == 0)
	{
		ft_putendl("You must specify a file path...");
		exit(ERROR);
	}
	if (!(f_stat = malloc(sizeof(struct stat))))
		exit(ERROR);
	if (lstat(path, f_stat) == -1)
		ft_perror(path);
	print_file_data(path, f_stat);
	return (0);
}
