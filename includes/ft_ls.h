/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/21 14:16:39 by pforciol         ###   ########.fr       */
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
	struct stat		stats;
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

/* ARGS UTILS */
t_list				*ls_getarg(char *arg, t_list *l_args, int *v_a);
t_list				*ls_getfile(char *parent_name, char *name, t_list *l_args);


/* DIRECTORY */
t_list				*ls_opendir(t_list *parent, t_list *l_args, t_opt *opt);

/* DISPLAY */
void				ls_print_dir(t_list *parent, t_list *l_args, t_opt *opt);

/* LST UTILS */
t_list				*lst_create(void *content, size_t size);
void				lst_append(t_list **list, t_list *to_append);
void				lst_clear(t_list **list);
int					get_lst_size(t_list *list);

/* OPTIONS */
t_opt				*ls_get_opts(char *argv[], int argc);

/* PROCESS */
void				ls_process(t_list *l_args, t_opt *opt, int list_len);

/* SORT */
t_list				*ls_lst_sort(t_opt *opt, t_list *l_args);

/* UTILS */
void				ls_get_columns_widths(t_list *l_args, unsigned int *w);
t_list				*ls_append_parent(t_list *parent, t_list *l_args);
void				ls_perror(const char *path, int do_exit);
void				ls_usage(void);

void				debug(t_opt *opt, int argc, t_list *l_args);

#endif
