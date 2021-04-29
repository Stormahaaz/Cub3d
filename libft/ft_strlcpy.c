/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:56:42 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/08 15:43:21 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	if (!dst)
		return (0);
	i = ft_strlen((char*)src);
	if (i >= dstsize)
		len = dstsize - 1;
	else
		len = i;
	if (dstsize)
	{
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (i);
}
