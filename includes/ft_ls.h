/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:57:14 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/16 14:52:18 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <stdio.h>

# define ERRNO_ERROR -1
# define MEM_ERROR -2

typedef struct		s_data
{
	char			*name;
	char			mode;
	int				is_dir;
	struct stat		stat;
}					t_data;

typedef struct		s_opt
{
	int				rr;
	int				a;
	int				d;
	int				f;
	int				g;
	int				l;
	int				r;
	int				t;
	int				one;
	int				nb_opt;
}					t_opt;

t_list				*ls_opendir(t_list *parent, t_list *l_args, t_opt *opt);

void				ls_print_l(t_data *entry, t_data *parent, unsigned int *w,
								t_opt *opt);

char				ls_get_mode(mode_t mode);
void				ls_print_w_color(char *name, mode_t mode);

void				ls_print_dir(t_list *parent, t_list *l_args, t_opt *opt);

t_list				*lst_create(void *content, size_t size);
void				lst_append(t_list **list, t_list *to_append);
void				lst_clear(t_list **list);
int					get_lst_size(t_list *list);

t_list				*ls_set_parent(t_list *prt, t_list *l_args);
void				ls_print_name(t_data *entry, t_data *parent, mode_t mode);

t_opt				*ls_get_opts(char *argv[], int argc);

void				ls_process(t_list *l_args, t_opt *opt, int ac);

t_list				*ls_lst_sort(t_opt *opt, t_list *l_args);

void				ls_get_col_widths(t_list *l_args, unsigned int *w, int i);
void				ls_error(const char *path, int error);
void				ls_usage(void);
void				ls_add_spaces(int width, int len, int sp);
void				ft_putcolor(char *str, char *color, char *bg, char *format);

#endif
