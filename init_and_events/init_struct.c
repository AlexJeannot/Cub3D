#include "../includes/second_cube.h"

void init(void)
{
  t_win	*new_elem;

  new_elem = (t_win *)malloc(sizeof(t_win));
  win = new_elem;

  win->mlx_ptr = mlx_init();
  win->width = 1000;
  win->height = 800;
  win->floor_color = 6464927;
  win->ceiling_color = 12750331;
  win->wall_color = 13922558;
  win->have_sprite = 0;
  win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, "TEST_WIN");
}

void init_map(void)
{
  t_map	*new_elem;

  new_elem = (t_map *)malloc(sizeof(t_map));
  win->my_map = new_elem;

  char **str_map;
  char *str_1;
  char *str_2;
  char *str_3;
  char *str_4;
  char *str_5;
  char *str_6;
  char *str_7;
  char *str_8;
  char *str_9;
  char *str_10;
  char *str_11;
  char *str_12;
  char *str_13;
  char *str_14;
  char *str_15;
  char *str_16;
  char *str_17;
  char *str_18;
  char *str_19;
  char *str_20;
  char *str_21;
  char *str_22;
  char *str_23;
  char *str_24;

  str_1 = malloc(sizeof(char) * 25);
  str_2 = malloc(sizeof(char) * 25);
  str_3 = malloc(sizeof(char) * 25);
  str_4 = malloc(sizeof(char) * 25);
  str_5 = malloc(sizeof(char) * 25);
  str_6 = malloc(sizeof(char) * 25);
  str_7 = malloc(sizeof(char) * 25);
  str_8 = malloc(sizeof(char) * 25);
  str_9 = malloc(sizeof(char) * 25);
  str_10 = malloc(sizeof(char) * 25);
  str_11 = malloc(sizeof(char) * 25);
  str_12 = malloc(sizeof(char) * 25);
  str_13 = malloc(sizeof(char) * 25);
  str_14 = malloc(sizeof(char) * 25);
  str_15 = malloc(sizeof(char) * 25);
  str_16 = malloc(sizeof(char) * 25);
  str_17 = malloc(sizeof(char) * 25);
  str_18 = malloc(sizeof(char) * 25);
  str_19 = malloc(sizeof(char) * 25);
  str_20 = malloc(sizeof(char) * 25);
  str_21 = malloc(sizeof(char) * 25);
  str_22 = malloc(sizeof(char) * 25);
  str_23 = malloc(sizeof(char) * 25);
  str_24 = malloc(sizeof(char) * 25);

  str_map = malloc((sizeof(char*) * 24)); // + (sizeof(char) * 66)

  str_1 = "111111111111111111111111";
  str_2 = "100000000101000000000001";
  str_3 = "100000000121000000000001";
  str_4 = "100000000101000000000001";
  str_5 = "100000000000000000000001";
  str_6 = "100000000000000000000001";
  str_7 = "100000000000000000000001";
  str_8 = "100000000000000000000001";
  str_9 = "100000000000000000000001";
  str_10 = "111110000000000000000001";
  str_11 = "100000000000000000000001";
  str_12 = "100000000000000000000001";
  str_13 = "100000000000000000000001";
  str_14 = "100000000001100000001111";
  str_15 = "100000000000000000000001";
  str_16 = "100000001010101000000001";
  str_17 = "100000000101010000000001";
  str_18 = "100000001010101000000001";
  str_19 = "100000000000000000020001";
  str_20 = "100000000001110000000001";
  str_21 = "100000200000000000000001";
  str_22 = "100000000000010000000001";
  str_23 = "100000000000010000000001";
  str_24 = "111111111111111111111111";

  str_map[0] = str_1;
  str_map[1] = str_2;
  str_map[2] = str_3;
  str_map[3] = str_4;
  str_map[4] = str_5;
  str_map[5] = str_6;
  str_map[6] = str_7;
  str_map[7] = str_8;
  str_map[8] = str_9;
  str_map[9] = str_10;
  str_map[10] = str_11;
  str_map[11] = str_12;
  str_map[12] = str_13;
  str_map[13] = str_14;
  str_map[14] = str_15;
  str_map[15] = str_16;
  str_map[16] = str_17;
  str_map[17] = str_18;
  str_map[18] = str_19;
  str_map[19] = str_20;
  str_map[20] = str_21;
  str_map[21] = str_22;
  str_map[22] = str_23;
  str_map[23] = str_24;

  win->my_map->map = str_map;
  win->my_map->map_name = "TEST";
  win->my_map->width = 24;
  win->my_map->height = 24;
}

void init_keybuffer(void)
{
  t_keybuffer	*new_elem;

  new_elem = (t_keybuffer *)malloc(sizeof(t_keybuffer));
  win->keybuffer = new_elem;

  win->keybuffer->toward = 0;
  win->keybuffer->backward = 0;
  win->keybuffer->left = 0;
  win->keybuffer->right = 0;
  win->keybuffer->turn_left = 0;
  win->keybuffer->turn_right = 0;
  win->keybuffer->cam_up = 0;
  win->keybuffer->cam_down = 0;
  win->keybuffer->exit = 0;
}

void init_player(void)
{
  t_player	*new_elem;

  new_elem = (t_player *)malloc(sizeof(t_player));
  win->player = new_elem;

  win->player->pos_x = 22;
  win->player->pos_y = 12;
  win->player->dir_x = -1.0;
  win->player->dir_y = 0.0;
  win->player->plane_x = 0.00;
  win->player->plane_y = 0.66;
  win->player->rotate_speed = 0.05;
  win->player->speed = 0.25;
  win->player->cam_height = 1.0;
}

void init_image(void)
{
  t_image	*new_elem;

  new_elem = (t_image *)malloc(sizeof(t_image));
  win->img = new_elem;

  win->img->img_ptr = mlx_new_image(win->mlx_ptr, win->width, win->height);
  win->img->width = win->width;
  win->img->height = win->height;
  win->img->size_line = 0;
  win->img->bpp = 0;
  win->img->endian = 0;
  win->img->data = mlx_get_data_addr(win->img->img_ptr, &win->img->bpp,	&win->img->size_line, &win->img->endian);
}

void init_texture_array(void)
{
  t_image **new_tex_array;
  new_tex_array = malloc(sizeof(t_image *) * 4);
  win->textures = new_tex_array;
}

void init_texture(char *path, int index)
{
  static int i;
  t_image *new_tex;

  new_tex = (t_image *)malloc(sizeof(t_image));

  /*new_tex->width = w;
  new_tex->height = h;
  new_tex->size_line = 0;
  new_tex->bpp = 0;
  new_tex->endian = 0;*/
  new_tex->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, path, &new_tex->width, &new_tex->height);

  new_tex->data = mlx_get_data_addr(new_tex->img_ptr, &new_tex->bpp, &new_tex->size_line, &new_tex->endian);
  win->textures[index] = new_tex;
  if (index == 0)
    config->texture_no = 1;
  else if (index == 1)
    config->texture_so = 1;
  else if (index == 2)
    config->texture_we = 1;
  else if (index == 3)
    config->texture_ea = 1;
  free(path);

  i++;
}
