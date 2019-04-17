/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:40:04 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/10 17:53:04 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s12;
	const unsigned char	*s22;

	s12 = s1;
	s22 = s2;
	i = 0;
	while (i < n)
	{
		if (s12[i] != s22[i] || s12 == '\0' || s22 == '\0')
			return (s12[i] - s22[i]);
		i++;
	}
	return (0);
}
