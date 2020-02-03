#ifndef SECOND_CUBE_H
# define SECOND_CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libraries/minilibx/mlx.h"
//# include "../libraries/libft/libft.a"
# include "../get_next_line/get_next_line.h"


# define OK 1
# define KO -1

typedef struct s_map
{
  char **map;
  char *map_str;
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
  int exit;
} t_keybuffer;

typedef struct s_player
{
  double pos_x;
  double pos_y;
  double dir_x;
  double dir_y;
  double plane_x;
  double plane_y;
  double rotate_speed;
  double speed;
  double cam_height;
//  int health;
} t_player;

typedef struct s_config
{
  int resolution;
  int texture_no;
  int texture_so;
  int texture_we;
  int texture_ea;
  int rgb_f;
  int rgb_c;
  int sprite;
  int map;
  int player_position;
} t_config;

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

typedef struct			s_draw_sprite
{
	int					i;
  struct s_sprite_list **sprite_list;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_width;
	int					draw_start_x;
	int					draw_end_x;
	int					stripe;
	int					y;
	int					d;
	int					tex_x;
	int					tex_y;
	int					color;
	int					totcolor;
} t_draw_sprites;

typedef struct s_sprites
{
  int x;
  int y;
  struct s_sprites *next;

} t_sprites;

typedef struct s_sprite_list
{
  int x;
  int y;
} t_sprite_list;

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
	double				dir_x;
	double				dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
  double        wall_x;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					wall_height;
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
  t_map *my_map;
  t_keybuffer *keybuffer;
  t_player *player;
  t_image *img;
  t_image **textures;
  t_image *sprite;
  t_sprites *displayable_sprite;
  int have_sprite;
//  t_sound *sound;
} t_win;


t_win *win;
t_ray *ray;
t_line *line;
t_draw_sprites *sp;
t_config *config;

//second_cube
void draw(void);
int loop(void);


/* ENGINE */
//display_wall
void	texture_on_img(int x, int y);
void vert_tex(int y0, int y1);

//display_floor_and_ceiling
void		pixel_put_to_image(int color, int x, int y);
void vert(int color, int y0, int y1);

//display_sprite
void			calcul_values(void);
void			pix_on_sprite_image(void);
void			is_black(void);
void draw_sprite(t_sprite_list *sprite_pos);
void diplay_sprite(void);

//raycasting
void calcul_wall_distance(void);
void find_wall_or_sprite(void);
void calcul_wall_height(void);
void calcul_wall_ordinate(void);
void calcul_wall_x(void);


/*INIT_AND_EVENT*/
//event_keys
int		key_released(int key);
int		key_pressed(int key);
int		key_manager(void);

//event_window.c
int		end_game(void);
void exit_game(char *str);

//init_struct
void init(void);
void init_map(void);
void init_keybuffer(void);
void init_player(void);
void init_image(void);
void init_texture(char *path, int index);
void init_texture_array(void);

//init_struct_2
void init_ray(void);
void init_ray_values(void);


/*MANAGERS*/
//manage_camera.c
void	turn_left(void);
void	turn_right(void);

//manage_motion
void	move_forward(void);
void	move_backward(void);
void	move_left(void);
void	move_right(void);

//manage_sprites
void set_sprite(char *path);
void add_displayable_sprite(void);
void sort_displayable_sprites(void);
void delete_diplayed_sprites(void);
void into_list(void);


/*PARSING*/
//check_error.c
int check_arg(char *str);
int check_open_config(char *path);
int check_error_rgb_value(int color_value, char color, char type);
int check_coma_between_rgb(char c, char color, char type);
void error_before_rgb_value(int color, char type);
void check_map_error(void);
void check_top_and_bottom_map(int limit);
void check_all_config_elem_before_map(void);

//information_type
int is_resolution(char *str);
int is_texture(char *str);
int is_rgb(char *str);
int is_sprite(char *str);
int is_map(char *str);

//parsing_config.c
void init_config(void);
int parse_config(char *path);
void parse_resolution(char *str);
void parse_texture(char *str, int index);
int create_rgb(int color_value, int rgb, char color, char type);
void parse_rgb(char *str);
void parse_sprite(char *str);
void parse_map(char *str);
void map_into_array(void);
int set_player_position(int x, int y, char orientation);
void set_player_dir_n_or_s(char orientation);
void set_player_dir_e_or_w(char orientation);


/*ANNEXES*/
//annexes.c
int	ft_atoi_cub(const char *nb);
char	*ft_strjoin_cub(char *str_1, char *str_2, int len_1, int len_2);
int ft_strlen(char *str);
int ft_strlen_without_space(char *str);





#endif
