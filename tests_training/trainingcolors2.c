/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainingcolors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:26:08 by gupatric          #+#    #+#             */
/*   Updated: 2021/02/10 15:37:16 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int		ft_get_int_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		ft_get_t(int trgb)
{
	return ((trgb & (0xFF << 24)) >> 24);
}

int		ft_get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

int		ft_get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8); 
}

int		ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		ft_add_shade(double distance, int color)
{
	int		nt = ft_get_t(color);
	int		nr = ft_get_r(color) * (1 - distance);
	int		ng = ft_get_g(color) * (1 - distance);
	int		nb = ft_get_b(color) * (1 - distance);

	return (ft_get_int_trgb(nt, nr, ng, nb));
}

int		ft_get_opposite(int color)
{
	int i = 0;

	int r  = ft_get_r(color);
	int g  = ft_get_g(color);
	int b  = ft_get_b(color);

	while (r++ < 255)
		i++;
	r = i;
	i = 0;
	while (g++ < 255)
		i++;
	g = i;
	i = 0;
	while (b++ < 255)
		i++;
	b = i;
	return (0 << 24 | r << 16 | g << 8 | b); 
}

// Part using functions to make a program

int		main(int ac, char **av)
{
	if (ac != 2 && ac != 7)
	{
		printf("RTFM !");
		return (0);
	}
	if (ac == 2)
	{
		int color = ft_atoi(av[1]);
		printf("code rgb for %s is %d ", av[1], ft_get_t(color));
		printf("%d ", ft_get_r(color));
		printf("%d ", ft_get_g(color));
		printf("%d.\n", ft_get_b(color));
		return (0);
	}
	double	distance = atof(av[1]);
	int		nt = ft_atoi(av[2]);
	int		nr = ft_atoi(av[3]);
	int		ng = ft_atoi(av[4]);
	int		nb = ft_atoi(av[5]);
	
	int		trgb = ft_get_int_trgb(nt, nr, ng, nb);
	int		trgb_shade = ft_add_shade(distance, trgb);
	int		trgb_opposite = ft_get_opposite(trgb);

	printf("original color hexa code  = %X, original color int = %d.\n", trgb, trgb);
	if (!ft_memcmp(av[6], "shade", ft_strlen("shade")))
	{
		printf("shaded color hexa code = %X\n", trgb_shade);
		printf("shade color code rgb = %d %d %d\n", ft_get_r(trgb_shade), ft_get_g(trgb_shade), ft_get_b(trgb_shade));
	}
	else if (!ft_memcmp(av[6], "opposite", ft_strlen("opposite")))
		printf("opposite = %X\n", trgb_opposite);
	else if (!ft_memcmp(av[6], "RGB CODE", ft_strlen("RGB CODE")))
	return (0);
}
