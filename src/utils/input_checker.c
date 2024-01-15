/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:11:11 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 22:43:56 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quote_check(char *input)
{
	int	i;
	int	quote;
	int	dquote;

	i = 0;
	quote = 0;
	dquote = 0;
	while (input[i])
	{
		if (input[i] == '\'' && dquote == 0)
			quote = !quote;
		if (input[i] == '\"' && quote == 0)
			dquote = !dquote;
		i++;
	}
	if (quote == 1 || dquote == 1)
	{
		ft_putstr_fd("Error: quote not closed\n", 1);
		return (0);
	}
	return (1);
}

int	ft_not_interpret(char **splitter)
{
	int	i;

	i = 0;
	while (splitter[i])
	{
		if (splitter[i][0] == ';' || splitter[i][0] == '\\')
		{
			ft_error(splitter[i][0], 0);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_strange_chars(t_expand *exp)
{
	while (exp)
	{
		if (exp->str && ft_is_redir(exp->str))
		{
			if (!exp->next)
				return ('r');
		}
		if (exp->str && exp->str[0] == '|')
		{
			if (exp->next && exp->next->str && exp->next->str[0] == '|')
				return ('q');
			if (!exp->next)
				return ('x');
		}
		if (exp->str && exp->str[0] == '&')
			return ('n');
		if (exp->str && exp->str[0] == ';')
			return ('s');
		exp = exp->next;
	}
	return (0);
}
