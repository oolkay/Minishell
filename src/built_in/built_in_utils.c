/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:28 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 21:25:41 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env_to_matrix(void)
{
	t_env	*env;
	char	**matrix;
	int		i;

	env = g_data->environmental;
	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	matrix = malloc(sizeof(char *) * (i + 1));
	i = 0;
	env = g_data->environmental;
	while (env)
	{
		matrix[i] = (char *)malloc(sizeof(char)
				* (ft_strlen(env->front) + ft_strlen(env->back) + 2));
		ft_strcpy(matrix[i], env->front);
		ft_strcat(matrix[i], "=");
		ft_strcat(matrix[i++], env->back);
		env = env->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	ft_delete_env(char *str)
{
	t_env	*env;
	t_env	*prev;

	env = g_data->environmental;
	prev = NULL;
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
		{
			if (prev == NULL)
				g_data->environmental = env->next;
			else
				prev->next = env->next;
			free_env_node(env);
			return ;
		}
		prev = env;
		env = env->next;
	}
	free_matrix(g_data->env);
	g_data->env = ft_env_to_matrix();
}

t_env	*ft_new_env(char *str)
{
	t_env	*env;
	t_env	*new;

	env = g_data->environmental;
	new = (t_env *)malloc(sizeof(t_env));
	new->front = ft_substr(str, 0, ft_strchr(str, '=') - str);
	new->back = ft_substr(str, ft_strchr(str, '=') - str + 1, ft_strlen(str));
	new->next = NULL;
	if (env == NULL)
		g_data->environmental = new;
	else
	{
		while (env->next)
			env = env->next;
		env->next = new;
	}
	return (new);
}

int	ft_is_valid_env(char *str)
{
	t_env	*env;

	env = g_data->environmental;
	if (!str)
		return (0);
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

void	ft_change_env(char *str, char *new_value)
{
	t_env	*env;

	env = g_data->environmental;
	if (!str)
		return ;
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
		{
			free(env->back);
			env->back = ft_strdup(new_value);
			return ;
		}
		env = env->next;
	}
}
