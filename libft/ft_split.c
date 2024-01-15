/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:12:49 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/27 15:30:15 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0' && str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			res++;
		}
	}
	return (res);
}

static int	ft_word_len(char const *str, int i, char c)
{
	int	res;

	res = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		res++;
	}
	return (res);
}

static int	is_this_char(const char *s, char c, int i)
{
	while (s[i] != '\0' && (s[i] == c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ini_i;
	int		m_i;
	char	**res;

	i = 0;
	m_i = 0;
	res = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		i = is_this_char(s, c, i);
		if (s[i] != '\0')
		{
			ini_i = 0;
			res[m_i] = malloc(sizeof(char) * (ft_word_len(s, i, c) + 1));
			while (s[i] != '\0' && s[i] != c)
				res[m_i][ini_i++] = s[i++];
			res[m_i++][ini_i] = '\0';
		}
	}
	res[m_i] = 0;
	return (res);
}
