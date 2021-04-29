/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:56:03 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/08 15:40:38 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (dst[i] && i < dstsize)
		i++;
	dstlen = i;
	if (i < dstsize)
	{
		while (i < dstsize - 1 && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (dstsize - 1 < dstlen)
		return (dstsize + srclen);
	return (dstlen + srclen);
}
