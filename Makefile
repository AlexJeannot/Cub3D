NAME = Cub3D

NAME_LIBFT = libft.a
LIBFT_DIR = ./libraries/libft/

SRCS = 				cub3d.c \
					srcs/annexes/annexes.c \
					srcs/annexes/annexes_2.c \
					srcs/engine/display_walls.c \
					srcs/engine/display_floor_and_ceiling.c \
					srcs/engine/display_sprites.c \
					srcs/engine/display_sprites_2.c \
					srcs/engine/raycasting.c \
					srcs/get_next_line/get_next_line.c \
					srcs/get_next_line/get_next_line_utils.c \
					srcs/init_and_events/events.c \
					srcs/init_and_events/init_struct.c \
					srcs/init_and_events/init_struct_2.c \
					srcs/init_and_events/init_struct_texture.c \
					srcs/managers/create_bitmap.c \
					srcs/managers/manage_camera.c \
					srcs/managers/manage_exit.c \
					srcs/managers/manage_keys.c \
					srcs/managers/manage_motion.c \
					srcs/managers/manage_sprites.c \
					srcs/managers/free_sprites.c \
					srcs/parsing/error_config.c \
					srcs/parsing/error_map.c \
					srcs/parsing/error_rgb.c \
					srcs/parsing/parse_config.c \
					srcs/parsing/parse_map.c \
					srcs/parsing/parse_resolution.c \
					srcs/parsing/parse_rgb.c \
					srcs/parsing/parse_sprite.c \
					srcs/parsing/parse_textures.c \
					srcs/parsing/set_player_position.c \

OBJS = $(SRCS:.c=.o)

CUB3D_H =	-I ./includes
GNL_H =	-I ./srcs/get_next_line
LIB_X = -lmlx -framework OpenGL -framework AppKit

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SAVE = save.bmp

all:		$(NAME)

$(NAME_LIBFT):
							make -C $(LIBFT_DIR)

$(NAME):			$(NAME_LIBFT)  $(OBJS)
							$(CC) $(FLAGS) $(LIB_X) $(CUB3D_H) $(GNL_H) $(OBJS) -o $(NAME)

clean:
							$(RM) $(OBJS)
							$(RM) $(SAVE)
							make clean -C $(LIBFT_DIR)

fclean:				clean
							$(RM) $(NAME) $(NAME_LIB)
							make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY: clean fclean all re
