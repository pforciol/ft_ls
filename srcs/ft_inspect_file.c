/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:16:30 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/20 11:09:39 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			set_file_name(t_file *f_data, const char *path)
{
	int len;

	len = ft_strlen(ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 1 : path);
	if (!(f_data->name = malloc(sizeof(char *) * len + 1)))
		exit(ERROR);
	f_data->name = ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 1 : path;
}

static void			set_file_type(t_file *f_data, mode_t mode)
{
	if (!(f_data->type = malloc(sizeof(char *) * 19)))
		exit(ERROR);
	f_data->type = NULL;
	f_data->type = (mode & S_IFMT) == S_IFREG ? "Fichier" : f_data->type;
	f_data->type = (mode & S_IFMT) == S_IFDIR ? "Répertoire" : f_data->type;
	f_data->type = (mode & S_IFMT) == S_IFLNK ? "Lien Symbolique" : f_data->type;
	f_data->type = (mode & S_IFMT) == S_IFBLK ? "Périphérique Block" : f_data->type;
	f_data->type = (mode & S_IFMT) == S_IFCHR ? "Périphérique Char" : f_data->type;
	f_data->type = (mode & S_IFMT) == S_IFSOCK ? "Socket" : f_data->type;
	f_data->type = (mode & S_IFMT) == S_IFIFO ? "FIFO" : f_data->type;
	if (f_data->type == NULL)
		f_data->type = "Fichier\0";
}

static void			set_file_modes(t_file *f_data, mode_t mode)
{
	if (!(f_data->modes = malloc(sizeof(char *) * 10)))
		exit (ERROR);
	f_data->modes[0] = (mode & S_IRUSR) ? 'r' : '-';
	f_data->modes[1] = (mode & S_IWUSR) ? 'w' : '-';
	f_data->modes[2] = (mode & S_IXUSR) ? 'x' : '-';
	f_data->modes[3] = (mode & S_IRGRP) ? 'r' : '-';
	f_data->modes[4] = (mode & S_IWGRP) ? 'w' : '-';
	f_data->modes[5] = (mode & S_IXGRP) ? 'x' : '-';
	f_data->modes[6] = (mode & S_IROTH) ? 'r' : '-';
	f_data->modes[7] = (mode & S_IWOTH) ? 'w' : '-';
	f_data->modes[8] = (mode & S_IXOTH) ? 'x' : '-';
	f_data->modes[9] = '\0';
}

static void			set_file_owner(t_file *f_data, uid_t uid, gid_t gid)
{
	int				len;

	len = ft_strlen(getpwuid(uid)->pw_name);
	if (!(f_data->owner = (char *)malloc(sizeof(char) * len + 1)))
		exit (ERROR);
	f_data->owner = ft_strjoin(getpwuid(uid)->pw_name, "\0");
	len = ft_strlen(getgrgid(gid)->gr_name);
	if (!(f_data->group = (char *)malloc(sizeof(char) * len + 1)))
		exit (ERROR);
	f_data->group = ft_strjoin(getgrgid(gid)->gr_name, "\0");
}

static t_file		*set_file_data(const char *path, struct stat *f_stat)
{
	t_file			*f_data;
	
	if (!(f_data = malloc(sizeof(t_file))))
		exit(ERROR);
	set_file_name(f_data, path);
	set_file_type(f_data, f_stat->st_mode);
	set_file_modes(f_data, f_stat->st_mode);
	f_data->links = f_stat->st_nlink;
	set_file_owner(f_data, f_stat->st_uid, f_stat->st_gid);
	f_data->size = f_stat->st_size;
	if (!(f_data->last_edit = (char *)malloc(sizeof(char) * 26)))
		exit (ERROR);
	time_t last_edit = f_stat->st_mtimespec.tv_sec;
	f_data->last_edit = ctime(&last_edit);

	return (f_data);
}

static void			print_file_data(const char *path, struct stat *f_stat)
{
	t_file			*f_data;

	f_data = set_file_data(path, f_stat);
	ft_putendl(ft_strjoin("Nom: ", f_data->name));
	ft_putendl(ft_strjoin("Type: ", f_data->type));
	ft_putendl(ft_strjoin("Modes: ", f_data->modes));
	ft_putstr("Nombre de liens: ");
	ft_putnbr(f_data->links);
	ft_putendl(ft_strjoin("\nProprietaire: ", f_data->owner));
	ft_putendl(ft_strjoin("Groupe: ", f_data->group));
	ft_putstr("Taille: ");
	ft_putnbr(f_data->size);
	ft_putstr(" octets\n");
	ft_putendl(ft_strjoin("Date de derniere modification: ", f_data->last_edit));
}

int					main(int argc, char const *argv[])
{
	const char		*path;
	struct stat		*f_stat;

	path = argv[1];
	if (path == NULL && argc == 1)
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
