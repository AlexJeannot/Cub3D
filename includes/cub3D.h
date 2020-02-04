#ifndef CUB3D_H
# define CUB3D_H

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

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_LEFT 123
# define KEY_RIGHT 124


typedef struct s_map
{
  char **map_array;
  char *map_str;
  const char *map_name;
  int width;
  int height;
} t_map;

typedef struct s_key
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
} t_key;

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

typedef struct			s_draw
{
	int					i;
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
} t_draw;

typedef struct s_displayable_sprites
{
  int x;
  int y;
  struct s_displayable_sprites *next;

} t_displayable_sprites;

typedef struct s_sprite_array
{
  int x;
  int y;
} t_sprite_array;

typedef struct			s_ray
{
	int					line_x;
	int					map_x;
	int					map_y;
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
  int have_sprite;
} t_win;

t_win *win;
t_map *map;
t_key *g_key;
t_player *player;
t_image *img;
t_ray *ray;
t_image **textures;
t_image *s_texture;
t_displayable_sprites *s_displayable; // liste chaine des sprites a afficher
t_sprite_array **s_array;
t_draw *s_draw;
t_config *config;

//cub3D
void draw(void);
int loop(void);


/*ANNEXES*/
//annexes.c
int	ft_atoi_cub(const char *nb_str);
char	*ft_strjoin_cub(char *str_1, char *str_2, int len_1, int len_2);
int ft_strlen(char *str);
int ft_strlen_without_space(char *str);
int browse_space(char *str);
int browse_number(char *str);


/* ENGINE */
//display_wall
void	display_pixel_texture(int x, int y);
void display_vertical_texture(int y_start, int y_end);

//display_floor_and_ceiling
void		display_pixel_color(int color, int x, int y);
void display_vertical_color(int color, int y_start, int y_end);


//display_sprite
void			calcul_values(void);
void			pix_on_sprite_image(void);
void			is_black(void);
void draw_sprite(t_sprite_array *sprite_pos);
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
void free_textures(void);
void free_elements(void);
void exit_game(char *str);

//init_struct
void init_win(void);
void init_map(void);
void init_key(void);
void init_player(void);
void init_img(void);
void init_texture_array(void);
void init_texture(char *path, int index);

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
void init_sprite(char *path);
t_displayable_sprites *init_displayable_sprite(void);
void add_displayable_sprite(void);
void sort_displayable_sprites(void);
void free_diplayed_sprites(void);
void sprites_into_array(void);


/*PARSING*/
//error_config
int arg_extension(char *str);
int open_config(char *path);
void check_all_config_elem_before_map(void);

//parse_config
void init_config(void);
void parse_line(char *str);
int parse_config(char *path);

//error_map
void check_map_error(void);
void check_top_and_bottom_map(int array);

//parse_map
int is_map(char *str);
void parse_map(char *str);
void map_into_array(void);

//set_player_position.c
int set_player_position(int x, int y, char orientation);
void set_player_dir_n_or_s(char orientation);
void set_player_dir_e_or_w(char orientation);

//error_rgb
int is_rgb(char *str);
int check_error_rgb_value(int color_value, char color, char type);
int check_coma_between_rgb(char c, char color, char type);
void error_before_rgb_value(char wrong_c, char color, char type);
void minus_before_rgb_value(char color, char type);

//parse_rgb
int create_rgb(int color_value, int rgb, char color, char type);
char set_color(int index);
void set_color_value(char *str, char color, char type);
void end_parse_rgb(char type, char last);
void parse_rgb(char *str);

//parse_resolution
int is_resolution(char *str);
void parse_resolution(char *str);

//parse_sprite
int is_sprite(char *str);
void sprite_extension(char *str);
void open_sprite_file(char *path);
void parse_sprite(char *str);

//parse_texture
int is_texture(char *str);
void texture_extension(char *str);
void open_texture_file(char *path, int index);
void parse_texture(char *str, int index);



#endif
