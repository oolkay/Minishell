/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:08:40 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/26 23:08:40 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*g_data;

// Prints prompt
char	*ft_prompt(void)
{
	char	*prompt;
	char	*pwd;
	int		i;

	i = 0;
	prompt = NULL;
	pwd = getcwd(NULL, 0);
	while (pwd[i] != '\0')
		i++;
	while (pwd[i] != '/')
		i--;
	prompt = ft_strdup("oolkay@acepni:~");
	prompt = ft_strjoin(prompt, pwd + i,
			ft_strlen(pwd + i) + ft_strlen(prompt) + 1);
	prompt = ft_strjoin(prompt, " $ ", ft_strlen(prompt) + 4);
	free(pwd);
	return (prompt);
}

void	set_and_execute(char *input)
{
	int			ret;
	char		**splitted_input;

	if (!ft_quote_check(input))
		return ;
	splitted_input = ft_parser(input, 0);
	if (ft_not_interpret(splitted_input) == 0)
		return ;
	g_data->exp = ft_expander(splitted_input, 0, 0, 0);
	free_matrix(splitted_input);
	g_data->exp = subsplit(g_data->exp);
	ret = check_strange_chars(g_data->exp);
	if (ret != 0)
	{
		ft_error(ret, 0);
		return ;
	}
	ft_fill_block(g_data->exp);
	free_exp(g_data->exp);
	free_pipes(g_data->fd_pipe, g_data->block_cnt);
}

void	ft_start_proccess(void)
{
	char	*input;
	char	*default_prompt;

	while (1)
	{
		ft_signal(1);
		default_prompt = ft_prompt();
		input = readline(default_prompt);
		if (input && *input && default_prompt)
		{
			set_and_execute(input);
			add_history(input);
		}
		else if (!input || *input != '\0')
		{
			free_string(default_prompt);
			free_string(input);
			ft_signal(3);
		}
		free_string(default_prompt);
		free_string(input);
	}
}

char	**ft_copy_matrix(char **matrix)
{
	int		i;
	char	**new_matrix;

	i = 0;
	while (matrix[i])
		i++;
	new_matrix = malloc(sizeof(char *) * (i + 1));
	if (!new_matrix)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		if (!new_matrix[i])
			return (NULL);
		i++;
	}
	new_matrix[i] = NULL;
	return (new_matrix);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 1 || argv[1])
		ft_exit("! Too many arguments.\n", 0);
	ft_banner();
	g_data = malloc(sizeof(t_data));
	if (!g_data)
		return (-1);
	g_data->environmental = NULL;
	g_data->env = ft_copy_matrix(env);
	g_data->exit_status = 0;
	ft_fill_env(env);
	ft_start_proccess();
	return (0);
}
