/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:07:45 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/30 13:30:23 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_getenv(char *str)
{
	t_env	*env;

	env = g_data->environmental;
	if (!str)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
			return (env->back);
		env = env->next;
	}
	return (NULL);
}

static int	get_cd_path(t_block *cmd, char **path)
{
	if (cmd->args[1] == NULL)
	{
		*path = ft_getenv("HOME");
		if (*path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (-1);
		}
	}
	else if (ft_strcmp(cmd->args[1], "-") == 0)
		*path = ft_getenv("OLDPWD");
	else
		*path = cmd->args[1];
	return (1);
}

int	ft_cd(t_block *cmd)
{
	char	*path;

	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (-1);
	}
	if (get_cd_path(cmd, &path) == -1)
		return (-1);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	return (0);
}
