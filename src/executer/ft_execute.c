/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:00:41 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/30 11:25:54 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_built_in(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	if (ft_strcmp(str, "pwd") == 0)
		return (1);
	if (ft_strcmp(str, "export") == 0)
		return (1);
	if (ft_strcmp(str, "unset") == 0)
		return (1);
	if (ft_strcmp(str, "env") == 0)
		return (1);
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

static void	ft_dup_fds(t_block *block)
{
	int	i;

	i = 0;
	(void)i;
	if (block->infile > 0)
	{
		dup2(block->infile, 0);
		close(block->infile);
	}
	if (block->outfile > 1)
	{
		dup2(block->outfile, 1);
		close(block->outfile);
	}
	while (i < g_data->block_cnt)
	{
		close(g_data->fd_pipe[i][0]);
		close(g_data->fd_pipe[i][1]);
		i++;
	}
}

static void	ft_execute_builtin(t_block *block, int tmp_in, int tmp_out)
{
	tmp_in = dup(0);
	tmp_out = dup(1);
	ft_dup_fds(block);
	if (ft_strcmp(block->cmd_name, "echo") == 0)
		g_data->exit_status = ft_echo(block);
	if (ft_strcmp(block->cmd_name, "cd") == 0)
		g_data->exit_status = ft_cd(block);
	if (ft_strcmp(block->cmd_name, "pwd") == 0)
		g_data->exit_status = ft_pwd();
	if (ft_strcmp(block->cmd_name, "export") == 0)
		g_data->exit_status = ft_export(block);
	if (ft_strcmp(block->cmd_name, "unset") == 0)
		g_data->exit_status = ft_unset(block);
	if (ft_strcmp(block->cmd_name, "env") == 0)
		g_data->exit_status = ft_env();
	if (ft_strcmp(block->cmd_name, "exit") == 0)
	{
		ft_putstr_fd("exit\n", 1);
		ft_exit_b(block);
	}
	dup2(tmp_in, 0);
	dup2(tmp_out, 1);
	close(tmp_in);
	close(tmp_out);
}

static int	ft_handle_builtin(t_block *block)
{
	int	pid;
	int	tmp_in;
	int	tmp_out;

	tmp_in = 0;
	tmp_out = 1;
	if (g_data->block_cnt > 1)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_execute_builtin(block, tmp_in, tmp_out);
			exit(127);
		}
		if (block->outfile > 1)
			close(block->outfile);
		if (block->infile > 0)
			close(block->infile);
		waitpid(pid, &g_data->exit_status, 0);
	}
	else
		ft_execute_builtin(block, tmp_in, tmp_out);
	return (1);
}

int	exec_ft(t_block *block, int indx)
{
	char	*path;
	int		pid;

	if (ft_is_built_in(block->cmd_name))
		return (ft_handle_builtin(block));
	if (ft_get_path(block, &path) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		ft_dup_fds(block);
		execve(path, block->args, g_data->env);
		ft_error('d', block);
		exit (g_data->exit_status);
	}
	if (block->outfile > 1)
		close(block->outfile);
	if (block->infile > 0)
		close(block->infile);
	if (indx > 0)
		close(g_data->fd_pipe[indx - 1][1]);
	waitpid(pid, &g_data->exit_status, 0);
	g_data->exit_status /= 256;
	free(path);
	return (1);
}
