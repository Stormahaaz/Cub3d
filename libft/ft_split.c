/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:42:53 by gupatric          #+#    #+#             */
/*   Updated: 2019/10/25 17:25:23 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_count(const char *str, char charset)
{
	int			k;
	int			i;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] && str[i] != charset)
		{
			k++;
			while (str[i] && str[i] != charset)
				i++;
		}
	}
	return (k);
}

static char		*ft_mword(const char *str, char charset)
{
	char		*word;
	int			i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	if (!(word = malloc(sizeof(*word) * i + 1)))
	{
		free(word);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != charset)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**ft_free_the_world(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char			**ft_split(const char *s, char c)
{
	char		**split;
	int			phr;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	phr = ft_count(s, c);
	if (!(split = malloc(sizeof(*split) * (phr + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(split[i] = ft_mword(s, c)))
				return (ft_free_the_world(split, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
