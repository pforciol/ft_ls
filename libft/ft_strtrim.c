/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:21:44 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/16 08:24:38 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		&& s[start] != '\0')
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > 0)
		end--;
	if (end == 0)
		return (ft_strnew(0));
	len = end - start + 1;
	if (!(str = ft_strsub(s, start, len)))
		return (NULL);
	str[len] = '\0';
	return (str);
}
