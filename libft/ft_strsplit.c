/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <pforciol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:04:37 by pforciol          #+#    #+#             */
/*   Updated: 2018/11/16 17:03:02 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(const char *s, char c)
{
	int i;
	int count;
	int in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int		ft_countchars(const char *s, char c, int i)
{
	int count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (j < ft_countwords(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(tab[j] = malloc(sizeof(char) * ft_countchars(s, c, i))))
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			tab[j][k++] = s[i++];
		tab[j++][k] = '\0';
	}
	tab[j] = 0;
	return (tab);
}
