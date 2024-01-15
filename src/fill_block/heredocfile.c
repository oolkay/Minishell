/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:40:30 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 22:43:13 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_to_file(char *line, int fd)
{
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

void	ft_get_heredoc_lines(char *delim, int fd)
{
	char	*line;
	char	*prompt;

	line = NULL;
	while (1)
	{
		ft_signal(1);
		prompt = ft_strdup("heredoc >> ");
		line = readline(prompt);
		if (line)
		{
			if (!ft_strcmp(line, delim))
				break ;
			else
				write_to_file(line, fd);
			free_string(prompt);
			free_string(line);
		}
		else
			ft_signal(3);
	}
	free_string(prompt);
	free_string(line);
	close(fd);
}

void	handle_heredoc_file(t_block *block, char *delim)
{
	int	pid;

	pipe(g_data->fd_heredoc);
	block->infile = g_data->fd_heredoc[0];
	pid = fork();
	if (pid == 0)
	{
		close(g_data->fd_heredoc[0]);
		ft_get_heredoc_lines(delim, g_data->fd_heredoc[1]);
		exit(0);
	}
	else
	{
		close(g_data->fd_heredoc[1]);
		waitpid(pid, NULL, 0);
	}
}
