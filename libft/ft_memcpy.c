/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:24:10 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/27 15:29:57 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_d;
	unsigned char	*p_s;

	p_d = (unsigned char *)dest;
	p_s = (unsigned char *)src;
	i = 0;
	if (!p_d && !p_s)
		return (0);
	while (i < n)
	{
		p_d[i] = p_s[i];
		i++;
	}
	return (dest);
}
