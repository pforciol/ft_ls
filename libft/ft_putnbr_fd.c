/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:04:15 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/15 14:11:20 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long nbr_long;

	nbr_long = n;
	if (nbr_long < 0)
	{
		ft_putchar_fd('-', fd);
		nbr_long = -nbr_long;
	}
	if (nbr_long >= 10)
		ft_putnbr_fd((nbr_long / 10), fd);
	ft_putchar_fd('0' + nbr_long % 10, fd);
}
