/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:20:46 by pforciol          #+#    #+#             */
/*   Updated: 2019/06/17 15:10:07 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			ls_swap(t_list *data, t_list *next_data)
{
	t_list			*tmp;

	tmp = data->content;
	data->content = next_data->content;
	next_data->content = tmp;
}

static int			ls_sort_lexically(t_opt *opt, t_data *first, t_data *second)
{
	if ((opt->r == 0 && ft_strcmp(first->name, second->name) > 0)
			|| (opt->r > 0 && ft_strcmp(first->name, second->name) < 0))
		return (1);
	return (0);
}

static int			ls_sort_by_time(t_opt *opt, t_data *first, t_data *second)
{
	if (first->time == second->time)
	{
		if (first->ntime == second->ntime)
			return (ls_sort_lexically(opt, first, second));
		if (opt->r == 1)
			return (first->ntime > second->ntime);
		else
			return (first->ntime < second->ntime);
	}
	if (opt->r == 1)
		return (first->time > second->time);
	else
		return (first->time < second->time);
	return (0);
}

t_list				*ls_lst_sort(t_opt *opt, t_list *l_args, int ac)
{
	int				i;
	t_list			*start;
	t_data			*first;
	t_data			*second;

	i = 0;
	start = l_args;
	while (l_args != NULL && l_args->next != NULL && i < (ac - 2 - opt->nb_opt))
	{
		first = ((t_data *)l_args->content);
		second = ((t_data *)l_args->next->content);
		if ((opt->t == 0 && ls_sort_lexically(opt, first, second) > 0)
				|| (opt->t > 0 && ls_sort_by_time(opt, first, second) > 0))
		{
			ls_swap(l_args, l_args->next);
			l_args = start;
			i = 0;
		}
		else
		{
			l_args = l_args->next;
			i++;
		}
	}
	return (start);
}
