/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:59:36 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/08 16:02:23 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*source;

	if (!dest && !src)
		return (0);
	source = (unsigned char*)src;
	dst = (unsigned char*)dest;
	if (source < dst)
		while (n--)
			dst[n] = source[n];
	else
		while (n--)
			*(dst++) = *(source++);
	return (dest);
}
