/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:32:35 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/16 10:00:46 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] != '+' && str[i] != '-' && ft_isdigit(str[i]) == 0)
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (ft_isdigit(str[i]) == 0)
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}
