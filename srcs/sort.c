/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:20:46 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/27 20:38:21 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			sort_lexically(t_opt *opt, t_list *l_args, int argc, int r)
{
	int				i;
	t_data			*tmp;
	t_list			*start;
	char			*first;
	char			*second;

	i = 0;
	start = l_args;
	while (l_args->next != NULL && i < (argc - 2 - opt->nb_opt))
	{
		first = (char *)((t_data *)l_args->content)->name;
		second = (char *)((t_data *)l_args->next->content)->name;
		if (r == 0 && ft_strcmp(first, second) > 0)
		{
			tmp = (t_data *)l_args->content;
			l_args->content = l_args->next->content;
			l_args->next->content = tmp;
			l_args = start;
			i = 0;
		}
		else if (r > 0 && ft_strcmp(first, second) < 0)
		{
			tmp = (t_data *)l_args->content;
			l_args->content = l_args->next->content;
			l_args->next->content = tmp;
			l_args = start;
			i = 0;
		}
		else
		{
			l_args = l_args->next;
			i++;
		}
	}
}

t_list				*ls_sort(t_opt *opt, t_list *l_args, int argc)
{
	if (opt->nb_opt == 0 || opt->lr == 0)
		sort_lexically(opt, l_args, argc, 0);
	else if (opt->lr == 1 && opt->lt == 0)
		sort_lexically(opt, l_args, argc, 1);
	return (l_args);
}
