/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:59:52 by gupatric          #+#    #+#             */
/*   Updated: 2019/10/25 16:35:55 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		beg;
	int		end;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	beg = 0;
	while (ft_check(s1[beg], set))
		beg++;
	if (beg == end)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	while (ft_check(s1[end - 1], set))
		end--;
	str = ft_substr(s1, beg, (end - beg));
	return (str);
}
