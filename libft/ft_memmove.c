/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:16:19 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/15 15:07:59 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len > 0)
		{
			len--;
			((char*)dst)[len] = ((const char*)src)[len];
		}
	}
	return (dst);
}
