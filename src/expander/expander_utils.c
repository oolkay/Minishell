/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:01:13 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 22:01:24 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_expand	*ft_add_tail_expander(t_expand *head, char *str)
{
	t_expand	*temp;
	t_expand	*new;

	temp = NULL;
	new = NULL;
	temp = head;
	new = (t_expand *)malloc(sizeof(t_expand));
	new->str = ft_strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->next = NULL;
	if (!(head))
		head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (head);
}

char	*ft_search_env(char *splitted_input)
{
	char	*str;
	t_env	*tmp;

	str = NULL;
	tmp = NULL;
	tmp = g_data->environmental;
	if (!splitted_input || *splitted_input == '\0')
		return (NULL);
	while (tmp)
	{
		if (ft_strncmp(splitted_input, tmp->front,
				ft_strlen(splitted_input)) == 0)
		{
			str = ft_strdup(tmp->back);
			return (str);
		}
		tmp = tmp->next;
	}
	return (str);
}

int	i_x(char c, char x)
{
	return ((c == '$' && (ft_isalnum(x) || x == '?')));
}

int	is_in_single_quote(char *str, int indx)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (i < indx)
	{
		if (str[i] == '\'')
			flag ++;
		i++;
	}
	if (flag && flag % 2 == 0)
		return (0);
	else if (strchr(str + indx + 1, '\'') != 0)
		return (1);
	return (0);
}
