/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:17:15 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/23 10:55:26 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				**ft_cpynargs(const char *argv[], int argc, t_opt *opt)
{
	char			**args;
	int				i;
	int				j;

	i = opt->nb_opt + 1;
	j = 0;
	if (!(args = (char **)malloc(sizeof(char *) * (argc - 1 - opt->nb_opt) + 1)))
		exit(ERROR);
	while (argv[i] != NULL && i < argc)
	{
		args[j] = (char *)argv[i];
		i++;
		j++;
	}
	return (args);
}

void				ft_perror(const char *path)
{
	char			*message;

	message = ft_strjoin("ft_ls: ", path);
	perror(message);
	exit(ERROR);
}

void				ft_usage(void)
{
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
	exit(ERROR);
}
