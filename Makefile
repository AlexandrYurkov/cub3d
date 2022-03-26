NAME = cub3D

HEADER = cub3d.h

LIB = libmlx.dylib ./libft/libft.a

SRCS =	map_reader.c \
		image_to_window.c print_img_3d.c \
		init_textures.c image_to_window_utils.c \
		player_movement.c ray_casting.c \
		graffiti.c graffiti_utils.c \
		main.c parser.c structure_init.c floor_parse.c \
		ceil_parse.c map_parser.c map_validating.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(OBJS): %.o:%.c $(HEADER)
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	cd ./libft && make && cd ..
	cd ./mlx && make && cp libmlx.dylib ../ && cd ..
	gcc $(OBJS) -o $(NAME) -L. $(LIB) -framework OpenGL -framework AppKit
	
clean:
	cd ./libft && make clean && cd ..
	cd ./mlx && make clean && cd ..
	/bin/rm -rf $(OBJS)

fclean: clean
	cd ./libft && make fclean && cd ..
	/bin/rm -rf libmlx.dylib
	/bin/rm -rf $(NAME)

norm:
	norminette *.c *.h libft/*.c libft/*.h

run: all norm
	./cub3D 1.cub

re: fclean all

.PHONY: all clean fclean re
