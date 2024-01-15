/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:24:52 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 22:40:02 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_words_nbr(char *str, int idx, int length)
{
	char	quote;

	quote = 0;
	while (str[idx] != '\0')
	{
		quote = 0;
		while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
			idx++;
		if (str[idx] && ft_is_quote(str[idx]))
		{
			length++;
			quote = str[idx];
			idx++;
			while (str[idx] && str[idx] != quote)
				idx++;
			idx++;
			while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
				idx++;
		}
		else if (str[idx] && !ft_is_delimiter(str[idx]) && length++ > -1)
			idx = find_len_util(str, idx, quote);
	}
	return (length);
}

static char	*ft_get_word_quote(char *str, char quote)
{
	int		idx;
	char	*word;
	int		len;

	idx = 1;
	while (str[idx] != '\0' && str[idx] != quote)
		idx++;
	if (str[idx])
		idx++;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
		idx++;
	len = idx;
	if (idx == 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	idx = -1;
	while (++idx < len)
		word[idx] = str[idx];
	word[idx] = '\0';
	return (word);
}

static char	*ft_get_word(char *str)
{
	int		idx;
	char	is_quote;
	char	*word;

	is_quote = 0;
	idx = 0;
	word = (char *)malloc(sizeof(char) * (ft_get_word_len(str) + 1));
	if (!word)
		return (NULL);
	while (str[idx] != '\0' && (!ft_is_delimiter(str[idx]) || is_quote > 0))
	{
		if (is_quote > 0 && is_quote == str[idx]
			&& str[idx + 1] && str[idx + 1] == ' ')
		{
			word[idx] = str[idx];
			idx++;
			break ;
		}
		if (ft_is_quote(str[idx]))
			is_quote = str[idx];
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	*patse_with_type(char *str, char **split, int idx)
{
	char	*ret;

	if (ft_is_quote(*str))
	{
		ret = ft_get_word_quote(str, *str);
		if (ret)
			split[idx] = ret;
		str += ft_strlen(ret);
	}
	else
	{
		ret = ft_get_word(str);
		if (ret)
			split[idx] = ret;
		str += ft_strlen(ret);
	}
	return (str);
}

char	**ft_parser(char *str, int idx)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (ft_words_nbr(str, 0, 0) + 1));
	while (*str && (*str || ft_is_delimiter(*str)))
	{
		while (*str && ft_is_delimiter(*str))
			str++;
		if (*str && !ft_is_delimiter(*str))
		{
			str = patse_with_type(str, split, idx);
			idx++;
		}
	}
	split[idx] = NULL;
	return (split);
}
