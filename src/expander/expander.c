/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:17:01 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 22:59:16 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*trim_env(char *line, int *k)
{
	int		j;
	char	*env;

	j = 0;
	while (line[j] && line[j] != ' ' && line[j] != '"'
		&& line[j] != '\'' && line[j] != '$')
		j++;
	env = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (line[j] && line[j] != ' ' && line[j] != '"'
		&& line[j] != '\'' && line[j] != '$')
	{
		env[j] = line[j];
		j++;
	}
	env[j] = '\0';
	*k += j;
	return (env);
}

static char	*ft_get_env(char *substr, int *indx)
{
	char	*env;
	char	*temp;

	temp = trim_env(substr + 1, indx);
	*indx += 1;
	if (temp[0] == '?')
	{
		env = ft_itoa(g_data->exit_status);
		free_string(temp);
		return (env);
	}
	env = ft_search_env(temp);
	free_string(temp);
	return (env);
}

static int	find_len(char *line)
{
	int		i;
	int		len;
	char	*env;

	i = 0;
	len = 0;
	while (line[i] != '\0')
	{
		if (i_x(line[i], line[i + 1]) && !is_in_single_quote(line, i))
		{
			env = ft_get_env(line + i, &i);
			if (!env)
				continue ;
			len += ft_strlen(env);
			free_string(env);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

static char	*ft_copier(char **line, int i, int j, int k)
{
	int		len;
	char	*str;
	char	*env;

	len = find_len(line[i]);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (line[i][j])
	{
		if (i_x(line[i][j], line[i][j + 1]) && !is_in_single_quote(line[i], j))
		{
			env = ft_get_env(line[i] + j, &j);
			if (env)
				str = ft_strjoin(str, env, len);
			k += ft_strlen(env);
			free_string(env);
		}
		else
		{
			str[k] = line[i][j++];
			str[++k] = '\0';
		}
	}
	return (str);
}

t_expand	*ft_expander(char **line, int i, int j, int k)
{
	t_expand	*exp;
	char		*str;
	char		*indx;

	exp = NULL;
	while (line[i])
	{
		indx = ft_strchr(line[i], '$');
		j = 0;
		k = 0;
		if (!indx)
			exp = ft_add_tail_expander(exp, line[i]);
		else
		{
			str = ft_copier(line, i, j, k);
			exp = ft_add_tail_expander(exp, str);
			free_string(str);
		}
		i++;
	}
	return (exp);
}
