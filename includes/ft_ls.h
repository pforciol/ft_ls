/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/14 15:58:55 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>

# define ERROR -1

void				ft_perror(const char *path);

typedef struct		s_file
{
	const char			*name;
	char			*type;
	char			*modes;
	int				links;
	char			*owner;
	char			*group;
	int				size;
	char			*last_edit;
}					t_file;

#endif