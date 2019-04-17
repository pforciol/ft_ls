/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:45:01 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/16 10:02:30 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*out;
	long	nb;
	int		i;

	nb = n;
	i = ft_intlen(nb);
	if (!(out = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	out[i--] = '\0';
	if (nb == 0)
	{
		out[i] = '0';
	}
	if (nb < 0)
	{
		out[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		out[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (out);
}
