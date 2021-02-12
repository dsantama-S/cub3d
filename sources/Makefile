LIB				= cub3d.h
SRCS			= 	error.c initialize_ray.c keys1.c \
					raydir.c ray_sprite.c rayc_sprite2.c \
					keys2.c get_next_line.c cub3d.c analyze.c \
					load_textures.c utilsrayc.c window.c main.c

OBJS			= $(SRCS:.c=.o)
RM				= rm -f
CFLAGS			= -g -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -lz
MLX				= libmlx.dylib
NAME			= Cub3d

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS) _libft
				@ar -rcs $(NAME) $(OBJS) $(shell find libft/ -name "*.o")
				@ranlib $(NAME)
				gcc -g ${LIBS} ${NAME} ${MLX} main.c
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
				$(RM) $(NAME) $(MLX) a.out
				@make fclean -C libft

re:				fclean $(NAME)

.PHONY:			all clean fclean re