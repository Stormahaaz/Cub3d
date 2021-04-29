/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:03:05 by gupatric          #+#    #+#             */
/*   Updated: 2021/03/25 18:28:38 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./include/libft.h"
# include "./include/colors.h"
# include <string.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"

# define BUFFER_SIZE	8

typedef struct		s_map
{
	char			start;
	int				r_x;
	int				r_y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprite;
	int				f;
	int				c;
	char			**map;
	int				x_map;
	int				y_map;
	char			save;
	int				error;
	char			*str_error;
	int				mstart;
}					t_map;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				trgb;
	int				virg;
	int				err;
	int				i;
}					t_color;

int					ft_isdatcub(char *map);
void				ft_init_parsed(t_map *parsed);
void				ft_parsing(char *map, t_map *parsed);
void				ft_error(t_map *map, char *str);
/*void				ft_parse_map(char *str, t_map *parsed);*/
void				ft_parse_texture_n_sprite(char *str, t_map *parsed);
void				ft_parse_r_n_color(char *str, t_map *parsed);
int					ft_atoi_res(char *str, int *i);
int					ft_get_int_trgb(int t, int r, int g, int b);
int					ft_get_t(int trgb);
int					ft_get_r(int trgb);
int					ft_get_g(int trgb);
int					ft_get_b(int trgb);
int					ft_add_shade(double distance, int color);
int					ft_get_opposite(int color);
int					ft_get_color(char *str);
int					ft_atoi_color(char *str, t_color *color);
void				ft_init_color(t_color *color);
int					ft_the_path(char *str, t_map *parsed, char **texture);

#endif
