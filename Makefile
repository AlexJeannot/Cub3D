test:
			gcc -Wall -Wextra -Werror -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit second_cube.c annexes/* engine/* get_next_line/get_next_line.c get_next_line/get_next_line_utils.c init_and_events/* managers/* parsing/*

# -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
