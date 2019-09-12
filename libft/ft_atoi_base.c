/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:45:57 by pforciol          #+#    #+#             */
/*   Updated: 2019/03/19 13:47:14 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base(char c, const char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, char *base)
{
	int		res;
	int		i;
	int		sign;
	int		base_len;

	base_len = ft_strlen(base);
	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] != '+' && str[i] != '-' && ft_isalnum(str[i]) == 0)
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (ft_isalnum(str[i]) == 0)
		i++;
	while (ft_base(str[i], base) != -1)
	{
		res = res * base_len + ft_base(str[i], base);
		i++;
	}
	return (sign * res);
}
