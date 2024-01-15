/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:18:27 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/29 22:29:16 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strsub(char *str, int start, int end)
{
	char	*new;
	int		i;

	i = 0;
	if (end >= start)
	{
		new = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!new)
			return (NULL);
	}
	else
		return (0);
	while (start < end)
	{
		new[i] = str[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

static t_expand	*assign_to_struct(t_expand *head, t_expand *tmp,
	t_expand *tmp_next, char *str[3])
{
	t_expand	*new;
	t_expand	*new2;

	free(tmp->str);
	if (str[0][0] != '\0')
	{
		tmp->str = str[0];
		new = (t_expand *)malloc(sizeof(t_expand));
		if (!new)
			return (NULL);
		tmp->next = new;
		tmp = new;
	}
	tmp->str = str[1];
	if (str[2][0] != '\0')
	{
		new2 = (t_expand *)malloc(sizeof(t_expand));
		if (!new2)
			return (NULL);
		new2->str = str[2];
		tmp->next = new2;
		tmp = new2;
	}
	tmp->next = tmp_next;
	return (head);
}

t_expand	*ft_handle_special_signs(t_expand *head, t_expand *tmp, char *type)
{
	char		*str[3];
	int			idx;

	if (ft_strcmp(tmp->str, type) == 0)
		return (head);
	idx = ft_strchr(tmp->str, type[0]) - tmp->str;
	str[0] = ft_strsub(tmp->str, 0, idx);
	str[1] = ft_strdup(type);
	str[2] = ft_strsub(tmp->str, idx + ft_strlen(type), ft_strlen(tmp->str));
	head = assign_to_struct(head, tmp, tmp->next, str);
	idx = 0;
	while (idx < 3)
	{
		if (str[idx][0] == '\0')
			free(str[idx]);
		idx++;
	}
	return (head);
}

t_expand	*check_special_char(t_expand *head, t_expand *temp)
{
	int	i;

	i = 0;
	while (temp->str[i] && temp->str[i] == ' ')
		i++;
	while (temp->str[i] && temp->str[i] != '<' && temp->str[i] != '>'
		&& temp->str[i] != '|')
		i++;
	if (temp->str[i] && temp->str[i] == '<')
	{
		if (temp->str[i + 1] == '<')
			return (ft_handle_special_signs(head, temp, "<<"));
		else
			return (ft_handle_special_signs(head, temp, "<"));
	}
	else if (temp->str[i] && temp->str[i] == '>')
	{
		if (temp->str[i + 1] == '>')
			return (ft_handle_special_signs(head, temp, ">>"));
		else
			return (ft_handle_special_signs(head, temp, ">"));
	}
	else if (temp->str[i] && temp->str[i] == '|')
		return (ft_handle_special_signs(head, temp, "|"));
	return (head);
}

t_expand	*subsplit(t_expand *expander)
{
	t_expand	*head;
	t_expand	*temp;

	temp = expander;
	head = expander;
	while (temp)
	{
		if (temp->str[0] != '\"' && temp->str[0] != '\'')
		{
			head = check_special_char(head, temp);
		}
		temp = temp->next;
	}
	return (head);
}
