/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:00:59 by gupatric          #+#    #+#             */
/*   Updated: 2019/10/21 18:01:13 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return ((char*)&s[i]);
	}
	while (s[i])
	{
		if ((char)c == s[i])
			rtn = (char *)(s + i);
		i++;
	}
	return (rtn);
}
