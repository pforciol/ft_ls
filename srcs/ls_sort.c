/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:20:46 by pforciol          #+#    #+#             */
/*   Updated: 2019/09/16 14:54:51 by pforciol         ###   ########.fr       */
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
	if (first->stat.st_mtimespec.tv_sec == second->stat.st_mtimespec.tv_sec)
	{
		if (first->stat.st_mtimespec.tv_nsec ==
				second->stat.st_mtimespec.tv_nsec)
			return (ls_sort_lexically(opt, first, second));
		if (opt->r == 1)
			return (first->stat.st_mtimespec.tv_nsec >
						second->stat.st_mtimespec.tv_nsec);
		else
			return (first->stat.st_mtimespec.tv_nsec <
						second->stat.st_mtimespec.tv_nsec);
	}
	if (opt->r == 1)
	{
		return (first->stat.st_mtimespec.tv_sec >
					second->stat.st_mtimespec.tv_sec);
	}
	else
	{
		return (first->stat.st_mtimespec.tv_sec <
					second->stat.st_mtimespec.tv_sec);
	}
	return (0);
}

t_list				*ls_lst_sort(t_opt *opt, t_list *l_args)
{
	t_list			*start;
	t_data			*first;
	t_data			*second;

	start = l_args;
	if (opt->f == 0)
	{
		while (l_args != NULL && l_args->next != NULL)
		{
			first = ((t_data *)l_args->content);
			second = ((t_data *)l_args->next->content);
			if ((opt->t == 0 && ls_sort_lexically(opt, first, second) > 0)
				|| (opt->t > 0 && ls_sort_by_time(opt, first, second) > 0))
			{
				ls_swap(l_args, l_args->next);
				l_args = start;
			}
			else
				l_args = l_args->next;
		}
	}
	return (start);
}
