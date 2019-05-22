/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/22 14:38:14 by pforciol         ###   ########.fr       */
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
	int				ur;
	int				la;
	int				ll;
	int				lr;
	int				lt;
	int				nb_opt;
}					t_opt;

t_opt				*ft_get_opts(const char *argv[], int argc);
void				ft_usage(void);
char				**ft_cpynargs(const char *argv[], int argc, t_opt *opt);
char				**ls_sort(t_opt *opt, char *args[], int argc);

//DEBUG
void				debug(t_opt *opt, int argc, char *args[]);

#endif
