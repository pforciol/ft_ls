/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:46:39 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/03 17:48:51 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_DISPLAY_L_H
# define LS_DISPLAY_L_H

# include "../includes/ft_ls.h"
# include <stdio.h>

void				ls_get_col_widths(t_list *l_args, unsigned int *w, int i);
t_list				*ls_set_parent(t_list *parent, t_list *l_args);
void				ls_perror(const char *path, int do_exit);
void				ls_usage(void);
void				ls_add_spaces(int width, int len, int sp);

#endif
