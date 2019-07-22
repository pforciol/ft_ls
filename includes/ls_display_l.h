/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_l.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:27:39 by pforciol          #+#    #+#             */
/*   Updated: 2019/07/22 15:30:50 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_DISPLAY_L_H
# define LS_DISPLAY_L_H

# include "../includes/ft_ls.h"

void			ls_print_uid_and_gid(t_data *ety, unsigned int *w);
void			ls_print_name(t_data *entry, t_data *parent, mode_t mode);
void			ls_print_mtime(time_t mtime);
void			ls_print_type(mode_t mode, t_data *entry, t_data *parent, 
									unsigned int *w);
char			*ls_permissions(mode_t mode, char *path);

#endif
