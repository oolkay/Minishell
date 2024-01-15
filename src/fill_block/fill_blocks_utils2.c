/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_blocks_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:31:00 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/30 10:48:58 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redir_error(t_block *block, char *str, char *filename)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	if (filename)
		free(filename);
	if (!block)
		return ;
	if (block->cmd_name)
		free_string(block->cmd_name);
	if (block->args)
		free_matrix(block->args);
	free(block);
}
