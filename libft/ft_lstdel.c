/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:22:10 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/16 14:53:58 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst != NULL && del != NULL)
	{
		while (*alst != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			tmp = (*alst)->next;
			free(*alst);
			*alst = tmp;
		}
		*alst = NULL;
	}
}
