/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:28:16 by pforciol          #+#    #+#             */
/*   Updated: 2019/04/25 18:32:04 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_strmode(mode_t mode, char * buf)
{
	const char	*chars;
	size_t i;

	chars = "rwxrwxrwx";
	i = 0;
	while (i < 9)
	{
		buf[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
		i++;
	}
	buf[9] = '\0';
}
