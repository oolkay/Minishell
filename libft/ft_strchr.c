/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:14:50 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/27 15:30:25 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	if (c > 127)
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == c)
			return ((char *)(s1));
		s1++;
	}
	if (c == '\0')
		return ((char *)s1);
	return ((char *)0);
}
