/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:26:21 by gupatric          #+#    #+#             */
/*   Updated: 2019/10/30 14:31:30 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_get_size(unsigned int n)
{
	int		size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

char			*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				size;

	size = 0;
	if (n >= 0)
		nb = n;
	if (n < 0)
	{
		nb = -1 * n;
		size++;
	}
	size = size + ft_get_size(nb);
	if (!(str = malloc(size * sizeof(char) + 1)))
		return (0);
	str[size] = '\0';
	while (size--)
	{
		if (nb > 0)
			str[size] = (nb % 10) + '0';
		if (size == 0 && n < 0)
			str[size] = '-';
		nb /= 10;
	}
	return (str);
}
