/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:28:55 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 22:05:17 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_error1(char type, t_block *block)
{
	if (type == 'u')
	{
		ft_putstr_fd(block->cmd_name, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (type == 'p')
	{
		ft_putstr_fd(" pipe open error\n", 2);
	}
	else if (type == 'q')
	{
		ft_putstr_fd("I cant handle '||'\n", 2);
	}
	else if (type == 'x')
	{
		ft_putstr_fd("no command after pipe\n", 2);
	}
}

static void	ft_error2(char type)
{
	if (type == 'n')
	{
		ft_putstr_fd("I cant handle '&' or '&&'\n", 2);
	}
	else if (type == ';')
	{
		ft_putstr_fd("I cant handle ';' or ';;'\n", 2);
	}
	else if (type == '\\')
	{
		ft_putstr_fd("I cant handle '\\'\n", 2);
	}
	else if (type == 'r')
	{
		ft_putstr_fd("No file after redirection\n", 2);
	}
}

int	ft_error(char type, t_block *block)
{
	ft_putstr_fd("minishell: ", 2);
	if (type == 'u' || type == 'p' || type == 'q' || type == 'x')
		ft_error1(type, block);
	else if (type == 'n' || type == ';' || type == '\\' || type == 'r')
		ft_error2(type);
	else if (type == 'd')
	{
		ft_putstr_fd(block->cmd_name, 2);
		ft_putstr_fd(": is a directory\n", 2);
		free_blocks(block);
	}
	else if (type == 'e')
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(block->args[1], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	return (1);
}
