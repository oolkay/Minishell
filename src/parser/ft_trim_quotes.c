/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:11:39 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/26 23:48:46 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_trim_len(char *str, char *quote, int i, int len)
{
	while (str[i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			*quote = str[i];
			i++;
			while (str[i] != '\0')
			{
				if (str[i] == *quote)
					break ;
				i++;
				len++;
			}
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*ft_trim_quotes(char *str, int i, int len)
{
	char	quote;
	char	*res;

	len = ft_get_trim_len(str, &quote, 0, 0);
	res = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote = str[i];
			i++;
			while (str[i] != '\0')
			{
				if (str[i] == quote)
					break ;
				res[len++] = str[i];
				i++;
			}
		}
		else
			res[len++] = str[i++];
	}
	res[len] = '\0';
	return (res);
}
