/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:15:15 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/16 17:09:09 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (ft_strlen(ndl) == 0)
		return ((char*)hstck);
	while (hstck[i] != '\0' && i <= n)
	{
		j = 0;
		while (hstck[i + j] == ndl[j] && (i + j) < n)
		{
			j++;
			if (ndl[j] == '\0')
				return ((char*)hstck + i);
		}
		i++;
	}
	return (NULL);
}
