/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:20:48 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/12 10:16:09 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <math.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include "../srcs/get_next_line/get_next_line.h"

# define OK 1
# define KO -1
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct			s_map
{
	int			width;
	int			height;
	char		*map_str;
	char		**map_array;
}						t_map;

typedef struct			s_key
{
	int	toward;
	int	backward;
	int left;
	int turn_left;
	int right;
	int turn_right;
	int exit;
}						t_key;

typedef struct			s_player
{
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double speed;
	double cam_height;
	double rotate_speed;
}						t_player;

typedef struct			s_config
{
	int map;
	int rgb_f;
	int rgb_c;
	int sprite;
	int resolution;
	int texture_no;
	int texture_so;
	int texture_we;
	int texture_ea;
	int player_position;
}						t_config;

typedef struct			s_image
{
	int		width;
	int		height;
	int		size_line;
	int		bpp;
	int		endian;
	void	*img_ptr;
	char	*data;
	char	*path;
}						t_image;

typedef struct			s_draw
{
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
	int		tex_x;
	int		tex_y;
	int		y;
	int		coef;
	int		sprite_width;
	int		sprite_height;
	int		sprite_screen_x;
	int		pix_color;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;

}						t_draw;

typedef struct			s_displayable_sprites
{
	int								x;
	int								y;
	struct s_displayable_sprites	*next;
}						t_displayable_sprites;

typedef struct			s_sprite_array
{
	int	x;
	int	y;
}						t_sprite_array;

typedef struct			s_ray
{
	int		line_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		draw_start;
	int		draw_end;
	int		wall_height;
	int		side;
	int		hit;
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	*z_buffer;
}						t_ray;

typedef struct			s_win
{
	int		width;
	int		height;
	int		floor_color;
	int		ceiling_color;
	int		have_sprite;
	int		save;
	int		win_set;
	void	*mlx_ptr;
	void	*win_ptr;
}						t_win;

t_win					*g_win;
t_map					*g_map;
t_key					*g_key;
t_player				*g_player;
t_image					*g_img;
t_ray					*g_ray;
t_image					**g_textures;
t_image					*g_s_texture;
t_displayable_sprites	*g_s_displayable;
t_sprite_array			**g_s_array;
t_draw					*g_s_draw;
t_config				*g_config;

void					draw_vert(void);
void					draw(void);
void					check_save(int argc, char **argv);
int						loop(void);
int						ft_atoi_cub(const char *nb_str);
char					*ft_strjoin_cub(char *str_1,
						char *str_2, int len_1, int len_2);
int						ft_strlen(char *str);
int						ft_strlen_without_space(char *str);
int						browse_space(char *str);
int						browse_number(char *str);
void					display_pixel_texture(int x, int y);
void					display_vertical_texture(int y_start, int y_end);
void					display_pixel_color(int color, int x, int y);
void					display_vertical_color(int color,
						int y_start, int y_end);
void					calcul_values(void);
void					check_line_length(void);
void					pix_on_sprite_image(void);
void					pix_to_be_diplay(void);
void					draw_sprite(t_sprite_array *sprite_pos);
void					diplay_sprite(void);
void					calcul_wall_distance(void);
void					find_wall_or_sprite(void);
void					calcul_wall_height(void);
void					calcul_wall_ordinate(void);
void					calcul_wall_x(void);
int						key_released(int key);
int						key_pressed(int key);
void					key_manager(void);
int						end_game(void);
void					free_struct(void);
void					free_textures(void);
void					free_elements(void);
void					exit_game(char *str);
void					init_win(void);
void					init_map(void);
void					init_key(void);
void					init_player(void);
void					init_img(void);
void					init_texture_array(void);
void					init_texture(char *path, int index);
void					init_texture_data(void);
void					init_sprite_data(void);
void					init_ray(void);
void					init_ray_values(void);
void					set_win_and_img(void);
void					turn_left(void);
void					turn_right(void);
void					forward(void);
void					backward(void);
void					left(void);
void					right(void);
void					init_sprite(char *path);
t_displayable_sprites	*init_displayable_sprite(void);
void					add_displayable_sprite(void);
void					sort_displayable_sprites(void);
void					free_sprites_list(void);
void					free_diplayed_sprites(void);
void					free_path_textures(void);
void					sprites_into_array(void);
void					set_bitmap_header(int fd,
						int bmp_size, int totalheader_size);
void					set_bitmap_infoheader(int fd, int infoheader_size);
void					set_data_bitmap(int fd);
void					create_bitmap(void);
int						arg_extension(char *str);
int						open_config(char *path);
int						start_map_into_array(void);
void					check_all_config_elem_before_map(void);
void					init_config(void);
void					parse_line(char *str);
void					check_in_map(int ret, char *str);
int						parse_config(char *path);
int						check_map_middle(int cmp_array, int cmp_str);
void					check_map_error(void);
void					check_top_and_bottom_map(int array);
int						is_map(char *str);
void					parse_map(char *str);
void					map_into_array(void);
int						set_player_position(int x, int y, char orientation);
void					set_player_dir_n_or_s(char orientation);
void					set_player_dir_e_or_w(char orientation);
int						is_rgb(char *str);
int						check_error_rgb_value(int color_value,
						char color, char type);
int						check_coma_between_rgb(char c,
						char color, char type);
void					end_parse_config(char *str, int pass);
void					error_before_rgb_value(char wrong_c,
						char color, char type);
void					minus_before_rgb_value(char color, char type);
int						create_rgb(int color_value,
						int rgb, char color, char type);
char					set_color(int index);
void					set_color_value(char *str, char color, char type);
void					end_parse_rgb(char type, char last);
void					parse_rgb(char *str);
int						is_resolution(char *str);
void					parse_resolution(char *str);
int						is_sprite(char *str);
void					sprite_extension(char *str);
void					open_sprite_file(char *path);
void					parse_sprite(char *str);
int						is_texture(char *str);
void					texture_extension(char *str);
void					open_texture_file(char *path, int index);
void					parse_texture(char *str, int index);
void					create_bitmap(void);
void					set_width(char *str, int cmp);
#endif
