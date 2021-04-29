/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:40:26 by gupatric          #+#    #+#             */
/*   Updated: 2021/03/30 12:40:27 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_parse_r_n_color(char *str, t_map *parsed)
{
	int		i;

	i = 1;
	if (*str == 'R')
	{
		if (parsed->r_x != 0 || parsed->r_y != 0)
			parsed->error = 2;
		parsed->r_x = ft_atoi_res(str, &i);
		parsed->r_y = ft_atoi_res(str, &i);
		i = ft_atoi_res(str, &i);
		if (i == -1 || i > 0 || parsed->r_x <= 0 || \
			parsed->r_y <= 0)
			parsed->error = 2;
	}
	if (*str == 'F' || *str == 'C')
	{
		if ((*str == 'C' && parsed->c != 0) || (*str == 'F' && parsed->f != 0))
			parsed->error = 2;
		if (*str == 'C')
			parsed->c = ft_get_color(str);
		if (*str == 'F')
			parsed->f = ft_get_color(str);
		if (parsed->f == -1 || parsed->c == -1)
			parsed->error = 2;
	}
}

void		ft_parse_texture_n_sprite(char *str, t_map *parsed)
{
	char	c;
	int		i;

	i = 0;
	c = *str;
	if (!ft_strncmp("NO", str, 2))
		i = ft_the_path(&str[2], parsed, &parsed->no);
	else if (!ft_strncmp("SO", str, 2))
		i = ft_the_path(&str[2], parsed, &parsed->so);
	else if (!ft_strncmp("EA", str, 2))
		i = ft_the_path(&str[2], parsed, &parsed->ea);
	else if (!ft_strncmp("WE", str, 2))
		i = ft_the_path(&str[2], parsed, &parsed->we);
	else if (!ft_strncmp("S", str, 1))
		i = ft_the_path(&str[1], parsed, &parsed->sprite);
	else if (i == 0 && c != 'F' && c != 'R' && c != 'C' && c != ' ' \
			&& c != '1' && c != '\0')
		parsed->error = 2;
		
}
/*
void		ft_parse_map(char *str, t_map *parsed)
{

}*/
