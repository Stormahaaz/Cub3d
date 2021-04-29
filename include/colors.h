/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:59:57 by gupatric          #+#    #+#             */
/*   Updated: 2021/02/05 15:40:12 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

int		ft_get_int_trgb(int t, int r, int g, int b);
int		ft_get_t(int trgb);
int		ft_get_r(int trgb);
int		ft_get_g(int trgb);
int		ft_get_b(int trgb);
int		ft_add_shade(double distance, int color);
int		ft_get_opposite(int color);

#endif
