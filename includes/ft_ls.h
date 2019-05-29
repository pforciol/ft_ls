/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/29 12:16:49 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define ERROR -1

typedef struct		s_data
{
	char			*name;
	char			*path;
	mode_t			mode;
	nlink_t			n_link;	
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	dev_t			rdev;
	time_t			time;
	long			ntime;
	quad_t			blocks;
}					t_data;

typedef struct		s_opt
{
	int				ur;
	int				la;
	int				ll;
	int				lr;
	int				lt;
	int				nb_opt;
}					t_opt;

t_opt				*ft_get_opts(char *argv[], int argc);
void				ft_usage(void);
t_list				*ft_getarg(char *arg, t_list *l_args, t_opt *opt);
t_list				*ls_sort(t_opt *opt, t_list *l_args, int argc);

void				ft_perror(const char *path, int do_exit);

//LST_UTILS
t_list				*lst_create(void *content, size_t size);
void				lst_append(t_list **list, t_list *to_append);
void				lst_clear(t_list **list);
int					get_lst_size(t_list *list);

//DEBUG
void				debug(t_opt *opt, int argc, t_list *l_args);

#endif
