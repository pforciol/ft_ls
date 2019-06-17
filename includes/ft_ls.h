/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/17 16:36:53 by pforciol         ###   ########.fr       */
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

# define ERROR -1
# define MAX(A, B) (((A) > (B)) ? (A) : (B))
# define MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef struct		s_data
{
	char			*name;
	char			*path;
	mode_t			mode;
	nlink_t			n_link;	
	struct passwd	uid;
	struct group	gid;
	off_t			size;
	dev_t			rdev;
	time_t			time;
	long			ntime;
	quad_t			blocks;
}					t_data;

typedef struct		s_opt
{
	int				rr;
	int				a;
	int				l;
	int				r;
	int				t;
	int				nb_opt;
}					t_opt;

t_opt				*ls_get_opts(char *argv[], int argc);
void				ls_usage(void);
t_list				*ls_getarg(char *arg, t_list *l_args, t_opt *opt, int *v_a);
t_list				*ls_lst_sort(t_opt *opt, t_list *l_args, int ac);

void				ls_process(t_list *l_args, t_opt *opt, int list_len);
void				ls_get_columns_widths(t_list *l_args, unsigned int *widths);
t_list				*ls_append_parent(t_list *parent, t_list *l_args);



void				ls_perror(const char *path, int do_exit);

//LST_UTILS
t_list				*lst_create(void *content, size_t size);
void				lst_append(t_list **list, t_list *to_append);
void				lst_clear(t_list **list);
int					get_lst_size(t_list *list);

//DEBUG
void				debug(t_opt *opt, int argc, t_list *l_args);

#endif
