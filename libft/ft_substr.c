/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:02:07 by gupatric          #+#    #+#             */
/*   Updated: 2019/11/09 11:20:44 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*cpy;

	i = 0;
	if (!s || !(cpy = malloc(((len + 1) * sizeof(char)))))
		return (0);
	if (start > ft_strlen(s))
	{
		cpy[0] = '\0';
		return (cpy);
	}
	while (i < len && s[start])
	{
		cpy[i] = s[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}
