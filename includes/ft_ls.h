/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/21 17:10:48 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define ERROR -1

void				ft_perror(const char *path);

typedef struct		s_file
{
	const char		*name;
	char			*type;
	char			*modes;
	int				links;
	char			*owner;
	char			*group;
	long long		size;
	char			*last_edit;
}					t_file;

typedef struct		s_opt
{
	int				R;
	int				a;
	int				l;
	int				r;
	int				t;
	int				nb_args;
}					t_opt;

t_opt				*ft_get_opts(const char *argv[], int argc);
void				ft_usage(void);

#endif
