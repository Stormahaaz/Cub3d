/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:57:03 by gupatric          #+#    #+#             */
/*   Updated: 2019/10/25 13:57:23 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dst;

	i = 0;
	source = (unsigned char*)src;
	dst = (unsigned char*)dest;
	while (i < n)
	{
		dst[i] = source[i];
		if ((unsigned char)c == dst[i])
			return ((void*)(dst + i + 1));
		i++;
	}
	return (0);
}
