/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:50:34 by gupatric          #+#    #+#             */
/*   Updated: 2021/03/29 08:50:37 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_parsed(t_map *parsed)
{
	parsed->r_x = 0;
	parsed->r_y = 0;
	parsed->no = NULL;
	parsed->so = NULL;
	parsed->we = NULL;
	parsed->ea = NULL;
	parsed->sprite = NULL;
	parsed->f = 0;
	parsed->c = 0;
	parsed->map = NULL;
	parsed->x_map = 0;
	parsed->y_map = 0;
	parsed->save = 0;
	parsed->error = 0;
	parsed->str_error = NULL;
	parsed->mstart = 0;
}

void	ft_init_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->virg = 0;
	color->trgb = 0;
	color->err = 0;
}
