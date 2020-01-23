#ifndef SECOND_CUBE_H
# define SECOND_CUBE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <math.h>
# include <time.h>
#include "minilibx/mlx.h"
#include "libft/includes/libft.h"

typedef struct s_map
{
  char **map;
  const char *map_name;
  int width;
  int height;
} t_map;

typedef struct s_keybuffer
{
  int toward;
  int backward;
  int left;
  int right;
  int turn_left;
  int turn_right;
  int cam_up;
  int cam_down;
} t_keybuffer;

typedef struct s_player
{
  double pos_x;
  double pos_y;
  double dir_x;
  double dir_y;
  double plane_x;
  double plane_y;
//  double rotate_speed;
//  double speed;
  double cam_height;
//  int health;
} t_player;

typedef struct s_image
{
  int width;
  int height;
  int size_line;
  int bpp;
  int endian;
  void *img_ptr;
  char *data;
} t_image;

/*typedef struct s_sprites
{
  int x;
  int y;
  struct s_sprites next;

} t_sprites;*/

typedef struct s_sound
{
  clock_t last_start_song;
} t_sound;

typedef struct			s_ray
{
	int					pix;
	int					mapx;
	int					mapy;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				*z_buffer;
}	t_ray;

typedef struct			s_line
{
	int					x;
	int					y;
	int					y0;
	int					y1;
	int					tex_x;
	int					tex_y;
}						t_line;

typedef struct s_win
{
  void *mlx_ptr;
  void *win_ptr;
  int width;
  int height;
  int floor_color;
  int ceiling_color;
  int wall_color;
//  int is_save;
//  int map_desc_found;
//  int after_found;
  t_map *map;
  t_keybuffer *keybuffer;
  t_player *player;
  t_image *img;
//  t_image **textures;
//  t_image *sprite;
//  t_sprites *sprites;
//  t_sound *sound;
} t_win;


t_win *win;
t_ray *ray;
t_line *line;
double	wall_x;

#endif
