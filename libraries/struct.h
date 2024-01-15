/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:08:43 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/27 15:08:43 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char			*front;
	char			*back;
	struct s_env	*next;
}					t_env;

typedef struct s_expand
{
	char				*str;
	struct s_expand		*next;
}	t_expand;

typedef struct s_data
{
	t_env		*environmental;
	t_expand	*exp;
	int			exit_status;
	char		**env;
	int			**fd_pipe;
	int			fd_heredoc[2];
	int			block_cnt;
}				t_data;

typedef struct s_block
{
	char	*cmd_name;
	char	**args;
	int		cmd_type;
	int		infile;
	int		outfile;
}	t_block;

#endif
