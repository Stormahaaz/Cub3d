/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <gupatric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:38:47 by gupatric          #+#    #+#             */
/*   Updated: 2021/03/25 18:04:36 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(char *map, t_map *parsed)
{
	int		fd;
	int		ret;
	char	*str;
	static int i = 0;

	ret = 1;
	str = NULL;
	if ((fd = open(map, O_DIRECTORY)) != -1)
		ft_error(parsed, "The file specified is a directory.");
	if ((fd = open(map, O_RDONLY)) == -1)
		ft_error(parsed, "The file specified is invalide.");
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		ft_parse_r_n_color(str, parsed);
		ft_parse_texture_n_sprite(str, parsed);
		ft_parse_map(str, parsed);
		if (parsed->error == 2)
		{
			printf("str while error = %s\n", str);
			ft_error(parsed, "An error have been detected while parsing");
		}
		free(str);
		i++;
	}
	close(fd);
}

int		main(int ac, char **av)
{
	t_map	parsed;

	ft_init_parsed(&parsed);
	if (!av[1] || ft_isdatcub(av[1]))
		ft_error(&parsed, "There is no map or the map have bad extension.");
	printf("File .cub detected, processing to the launch of the program.\n");
	if (ac == 3 && ft_strncmp(av[2], "--save", ft_strlen("--save")))
		ft_error(&parsed, "The second argument have to be \"--save\".");
	else if (ac == 3)
	{
		parsed.save = 1;
		printf("Arg \"--save\" detected, screen in game have been took.\n");
	}
	ft_parsing(av[1], &parsed);
	printf("x = %d.\ny = %d.\n", parsed.r_x, parsed.r_y);
	printf("NO = %s\nSO = %s\nEA = %s\nWE = %s\nSPRITE = %s\nF = %d\nC = %d\n", parsed.no, parsed.so, \
		parsed.ea, parsed.we, parsed.sprite, parsed.f, parsed.c);	
	return (0);
}