SRCS =	ft_parsing.c srcs/ft_init.c srcs/ft_parse_tools.c gnl/get_next_line.c \
		gnl/get_next_line_utils.c srcs/ft_error.c srcs/ft_parsing_map.c \
		srcs/ft_treat_color.c srcs/ft_treat_color2.c
		
NAME = cub3d
LIBFT_DIR = libft/
LIBFT = libft.a
MLX_DIR = minilibx-linux
MLX = libmlx.a
OBJS = ${SRCS:.c=.o}
HEADER = include
LIBS = -L ${MLX_DIR} -lmlx -L ${LIBFT_DIR} -lbft -lm -lbsd -lX11 -lXext
CC = gcc -Wall -Wextra -Werror

all : ${NAME}


${NAME} : ${OBJS} ${MLX}
		@make -C ${LIBFT_DIR}
		${CC} -o ${NAME} ${OBJS} -L ${LIBFT_DIR} -lft -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext 

${MLX} :
		@make -C ${MLX_DIR}

clean :
		rm -f ${OBJS}
		@make clean -C ${LIBFT_DIR}

fclean :
		rm -f ${NAME}

.PHONY : re flcean clean all