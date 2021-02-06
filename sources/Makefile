LIB				= cub3d.h
SRCS			= get_next_line.c cub3d.c analyze.c error.c initialize_ray.c raydir.c ray_sprite.c rayc_sprite2.c load_textures.c utilsrayc.c window.c main.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -lz
MLX				= libmlx.dylib

NAME			= cub3d.a

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS) _libft
				@ar -rcs $(NAME) $(OBJS) $(shell find libft/ -name "*.o")
				@ranlib $(NAME)

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

.c.o:
				gcc ${CFLAGS} -c $< -o $(<:.c=.o)

_libft:
				@make -C libft

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)
				@make clean -C libft

fclean:			clean
				$(RM) $(NAME) $(MLX)
				@make fclean -C libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re