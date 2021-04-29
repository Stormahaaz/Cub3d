/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:14:10 by gupatric          #+#    #+#             */
/*   Updated: 2021/03/29 08:14:12 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_isdatcub(char *map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (ft_strncmp(".cub", &map[i - 4], 4));
}

int		ft_atoi_res(char *str, int *i)
{
	int nb;

	nb = 0;
	while (str[*i] == 32 || str[*i] == '\t')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = (nb * 10) + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] != ' ' && str[*i] != '\0')
		return (-1);
	return (nb);
}

int		ft_atoi_color(char *str, t_color *color)
{
	int nb;

	nb = 0;
	while (str[color->i] == 32 || str[color->i] == '\t')
		color->i++;
	while (str[color->i] >= '0' && str[color->i] <= '9')
	{
		nb = (nb * 10) + (str[color->i] - '0');
		color->i++;
	}
	while (str[color->i] == 32)
		color->i++;
	if (str[color->i] != '\0' && str[color->i] != ',')
		return (color->err = -1);
	if (str[color->i] == ',')
	{
		color->virg++;
		color->i++;
	}
	if (nb > 255)
		return (-1);
	return (nb);
}

int		ft_get_color(char *str)
{
	t_color color;

	ft_init_color(&color);
	color.i = 1;
	color.r = ft_atoi_color(str, &color);
	color.g = ft_atoi_color(str, &color);
	color.b = ft_atoi_color(str, &color);
	color.err = ft_atoi_color(str, &color);
	if (color.r < 0 || color.g < 0 || color.b < 0 || color.virg != 2 \
		|| color.err != 0)
		return (-1);
	return (ft_get_int_trgb(0, color.r, color.g, color.b));
}

int		ft_the_path(char *str, t_map *parsed, char **texture)
{
	int	i;

	i = 0;
	if (*str != ' ')
		parsed->error = 2;
	while (*str == ' ')
		str++;
	if (ft_strncmp(str, "./", 2) || !(str + 2) || *texture)
		parsed->error = 2;
	while (str[i] != ' ' && str[i])
		i++;
	if (!(*texture = ft_substr(str, 0, i)))
		parsed->error = 2;
	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i])
		parsed->error = 2;
	return (1);
}
