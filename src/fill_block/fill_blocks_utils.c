/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_blocks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:37:39 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 23:38:37 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_arg_size(t_expand *exp)
{
	int	i;

	i = 0;
	while (exp && !ft_is_pipe(exp->str))
	{
		if (exp->str && !ft_is_redir(exp->str))
			i++;
		else if (exp->str && ft_is_redir(exp->str))
		{
			exp = exp->next;
		}
		exp = exp->next;
	}
	return (i);
}

char	**ft_fill_args(t_expand **exp, t_block *block, int arg_cnt)
{
	char	**args;
	int		i;

	i = -1;
	args = (char **)malloc(sizeof(char *) * (arg_cnt + 1));
	if (!args)
		return (NULL);
	while ((*exp) && !(ft_is_pipe((*exp)->str)))
	{
		if (ft_is_redir((*exp)->str))
		{
			if (handle_redir(block, exp) == -1)
				return (NULL);
		}
		else
		{
			args[++i] = ft_trim_quotes((*exp)->str, 0, 0);
			(*exp) = (*exp)->next;
		}
	}
	args[++i] = NULL;
	return (args);
}

int	ft_count_pipe(t_expand *exp)
{
	int	cnt;

	cnt = 0;
	while (exp)
	{
		if (exp->str && exp->str[0] == '|')
		{
			if (exp->next->str && exp->next->str[0] == '|')
				return (-1);
			cnt++;
		}
		exp = exp->next;
	}
	return (cnt);
}

int	ft_is_redir(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '>' || str[0] == '<')
		return (1);
	return (0);
}

int	ft_is_pipe(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (1);
	return (0);
}
