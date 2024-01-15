/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:24:09 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/26 23:24:09 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_len_util(char *str, int idx, char quote)
{
	while (str[idx] && (!ft_is_delimiter(str[idx]) || quote > 0))
	{
		if (quote > 0 && quote == str[idx]
			&& str[idx + 1] && str[idx + 1] == ' ')
		{
			idx++;
			break ;
		}
		if (ft_is_quote(str[idx]))
			quote = str[idx];
		idx++;
	}
	return (idx);
}

int	ft_get_word_len(char *str)
{
	int		idx;
	char	is_quote;

	idx = 0;
	is_quote = 0;
	while (str[idx] != '\0' && (!ft_is_delimiter(str[idx]) || is_quote > 0))
	{
		if (is_quote > 0 && is_quote == str[idx]
			&& str[idx + 1] && str[idx + 1] == ' ')
		{
			idx++;
			break ;
		}
		if (ft_is_quote(str[idx]))
			is_quote = str[idx];
		idx++;
	}
	return (idx);
}

int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}
