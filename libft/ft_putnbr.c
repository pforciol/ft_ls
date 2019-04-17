/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:33:02 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/15 14:06:18 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long nbr_long;

	nbr_long = n;
	if (nbr_long < 0)
	{
		ft_putchar('-');
		nbr_long = -nbr_long;
	}
	if (nbr_long >= 10)
		ft_putnbr(nbr_long / 10);
	ft_putchar('0' + nbr_long % 10);
}
