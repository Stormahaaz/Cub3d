/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:50:17 by gupatric          #+#    #+#             */
/*   Updated: 2021/04/12 16:50:19 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
