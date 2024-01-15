/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:03:03 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/27 15:31:03 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lastspot;

	lastspot = 0;
	if (c > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			lastspot = (char *)s;
		s++;
	}
	if (lastspot)
		return (lastspot);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
