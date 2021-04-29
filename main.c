#include "cub3d.h"
#include "./gnl/get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;
    char *line;
    int fd = open(av[1], O_RDONLY);
    while (get_next_line(fd, &line) > 0)
	{
        printf("%s\n", line);
		free(line);
	}
}
