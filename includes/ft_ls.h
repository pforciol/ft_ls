/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/27 12:17:26 by pforciol         ###   ########.fr       */
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

typedef struct		s_data
{
	const char		*name;
	int				is_dir;
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

t_opt				*ft_get_opts(const char *argv[], int argc);
void				ft_usage(void);
t_list				*ft_getargs(const char *argv[], int argc, t_opt *opt);
char				**ls_sort(t_opt *opt, char *args[], int argc);

//LST_UTILS
t_list				*lst_create(void *content, size_t size);
void				lst_append(t_list **list, t_list *to_append);
void				lst_clear(t_list **list);
int					get_lst_size(t_list *list);

//DEBUG
void				debug(t_opt *opt, int argc, t_list *l_args);

#endif
