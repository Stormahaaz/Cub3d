/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:15:05 by gupatric          #+#    #+#             */
/*   Updated: 2021/03/30 10:15:06 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_error(t_map *map, char *str)
{
	printf("Error\n%s\n", str);
	free(map->no);
	free(map->so);
	free(map->ea);
	free(map->we);
	free(map->sprite);
	exit(0);
}
