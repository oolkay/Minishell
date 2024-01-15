/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:15:53 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 21:40:05 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_block *cmd)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		if (ft_is_valid_env(cmd->args[i]))
		{
			ft_delete_env(cmd->args[i]);
		}
		i++;
	}
	free_matrix(g_data->env);
	g_data->env = ft_env_to_matrix();
	return (0);
}
