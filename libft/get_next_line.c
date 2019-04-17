/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:52:33 by pforciol          #+#    #+#             */
/*   Updated: 2019/03/13 12:58:30 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		gnl_read(const int fd, char **str)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	ft_bzero(buff, (BUFF_SIZE + 1));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		if (ft_strchr(*str, '\n') != NULL)
			break ;
		ft_bzero(buff, (BUFF_SIZE + 1));
	}
	return (ret);
}

static char		*gnl_check(char **str)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (*(*str + i) != '\n' && *(*str + i) != '\0')
		i++;
	line = ft_strsub(*str, 0, i);
	tmp = *str;
	*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i);
	free(tmp);
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str;
	int				ret;

	if (fd < 0)
		return (ERROR);
	if (!str)
		str = ft_strnew(0);
	if (ft_strchr(str, '\n') != NULL)
		*line = gnl_check(&str);
	else
	{
		if ((ret = gnl_read(fd, &str)) == END && !*str)
			return (END);
		if (ret == ERROR)
			return (ERROR);
		*line = gnl_check(&str);
	}
	return (SUCCESS);
}
