/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:10:23 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/27 15:10:23 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "define.h"
# include "includes.h"
# include "struct.h"

extern t_data	*g_data;
int			ft_quote_check(char *input);
int			ft_not_interpret(char **splitter);
int			check_strange_chars(t_expand *exp);
void		ft_banner(void);
void		ft_fill_env(char **env);
void		ft_exit(char *str, int status);
void		ft_start_proccess(void);
void		ft_signal(int flag);
t_expand	*ft_expander(char **line, int i, int j, int k);
char		**ft_parser(char *input, int i);
int			ft_get_word_len(char *str);
int			ft_is_quote(char c);
int			ft_is_delimiter(char c);
t_expand	*ft_add_tail_expander(t_expand *head, char *str);
int			is_in_single_quote(char *str, int indx);
int			ft_error(char type, t_block *block);
void		free_string(char *str);
void		free_matrix(char **str);
void		free_blocks(t_block *blocks);
void		free_exp(t_expand *exp);
void		free_pipes(int **pipefd, int cnt);
void		free_env(t_env *env);
char		*ft_strcat(char *dest, char *src);
t_expand	*subsplit(t_expand *expander);
char		*ft_search_env(char *splitted_input);
char		*ft_trim_quotes(char *str, int i, int len);
int			ft_exit_b(t_block *cmd);
int			ft_echo(t_block *cmd);
int			ft_pwd(void);
int			ft_cd(t_block *cmd);
int			ft_export(t_block *cmd);
int			ft_unset(t_block *cmd);
int			ft_env(void);
void		ft_delete_env(char *str);
t_env		*ft_new_env(char *str);
int			ft_is_valid_env(char *str);
void		ft_change_env(char *str, char *new_value);
char		*ft_strstr(char *big, char *little);
int			ft_get_path(t_block *block, char **path);
void		set_and_execute(char *input);
char		**ft_env_to_matrix(void);
void		ft_get_heredoc_lines(char *delim, int fd);
void		handle_heredoc_file(t_block *block, char *delim);
char		**ft_fill_args(t_expand **exp, t_block *block, int arg_cnt);
int			ft_arg_size(t_expand *exp);
int			ft_fill_block(t_expand *exp);
int			ft_is_redir(char *str);
int			ft_is_pipe(char *str);
int			exec_ft(t_block *block, int indx);
int			ft_count_pipe(t_expand *exp);
int			handle_redir(t_block *block, t_expand **exp);
void		free_env_node(t_env *env);
int			i_x(char c, char x);
int			find_len_util(char *str, int idx, char quote);
void		ft_redir_error(t_block *block, char *str, char *filename);

#endif
