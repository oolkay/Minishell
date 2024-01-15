/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:11:53 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/28 14:17:04 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(void)
{
	t_env	*env;

	env = g_data->environmental;
	while (env)
	{
		ft_putstr_fd(env->front, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(env->back, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (0);
}
