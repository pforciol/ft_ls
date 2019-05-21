/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:41:06 by pforciol          #+#    #+#             */
/*   Updated: 2019/05/21 16:44:30 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// int					main(int argc, char const *argv[])
// {
// 	DIR				*dir_ptr;
// 	const char		*path;
// 	struct dirent	*dir;

// 	(void)argc;
// 	path = ".";
// 	if (argv[1] != NULL)
// 		path = argv[1];
// 	if ((dir_ptr = opendir(path)) == NULL)
// 		ft_perror(path);
// 	else
// 	{
// 		while ((dir = readdir(dir_ptr)) != NULL)
// 		{
// 			ft_putendl(dir->d_name);
// 		}
// 		closedir(dir_ptr);
// 	}
// 	return (0);
// }

int					main(int argc, char const *argv[])
{
	//char			**args;
	t_opt			*opt;

	opt = ft_get_opts(argv, argc);
	printf("Value of opt.R %d\n", opt->R);
	printf("Value of opt.a %d\n", opt->a);
	printf("Value of opt.l %d\n", opt->l);
	printf("Value of opt.r %d\n", opt->r);
	printf("Value of opt.t %d\n", opt->t);
	return (0);
	
	// TODO: Catch options
	// TODO: Sort lexically argv tab
	// TODO: Select if directory or other
	// TODO: Get options and send them in options structure

}
