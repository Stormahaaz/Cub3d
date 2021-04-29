/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainingdrawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:52:06 by gupatric          #+#    #+#             */
/*   Updated: 2021/02/10 15:37:13 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "../include/colors.h"
#include "../minilibx-linux/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*) dst = color;
}

int				ft_rainbow(int colors)
{
	int			cr = ft_get_r(colors);
	int			cg = ft_get_g(colors);
	int			cb = ft_get_b(colors);

	if (cr == 255 && cb == 0)
	{
		cg++;
		if (cg == 255)
			cr--;
	}
	if (cg == 255 && cb == 0)
	{
		cr--;
		if (cr == 0)
			cb++;
	}
	if (cg == 255 && cr == 0)
	{
		cb++;
		if (cb == 255)
			cg--;
	}
	if (cb == 255 && cr == 0)
	{
		cg--;
		if (cg == 0)
			cr++;
	}
	if (cb == 255 && cg == 0)
	{
		cr++;
		if (cr == 255)
			cb--;
	}
	if (cr == 255 && cg == 0)
	{
		cb--;
	}
		return (0 << 24 | cr << 16 | cg << 8 | cb);
}

int				main()
{
	void 	*mlx;
	void 	*win;
	t_data	img;
	int		i = 0;
	int		y;
	double	shader = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Mlx train");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	while (i < 1080)
	{
		int		colors = 0x00FF0000;
		y = 0;
		while (y < 1920)
		{
			my_mlx_pixel_put(&img, y, i, ft_add_shade(shader, colors));
			colors = ft_rainbow(colors);
			y++;
		}
		shader = 0.000925925 * i;
		i++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
