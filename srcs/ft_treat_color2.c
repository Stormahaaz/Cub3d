/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_color2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:50:52 by gupatric          #+#    #+#             */
/*   Updated: 2021/04/12 16:50:59 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_add_shade(double distance, int color)
{
	int	nt;
	int	nr;
	int	ng;
	int	nb;

	nt = ft_get_t(color);
	nr = ft_get_r(color) * (1 - distance);
	nb = ft_get_b(color) * (1 - distance);
	ng = ft_get_g(color) * (1 - distance);
	return (ft_get_int_trgb(nt, nr, ng, nb));
}

int		ft_get_opposite(int color)
{
	int i;
	int r;
	int g;
	int b;

	i = 0;
	r = ft_get_r(color);
	g = ft_get_g(color);
	b = ft_get_b(color);
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
