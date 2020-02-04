#include "../includes/cub3D.h"

void init_win(void)
{
  if (!(win = (t_win *)malloc(sizeof(t_win))))
    exit_game("Error\nMemory allocation error\n");
  win->mlx_ptr = mlx_init();
  win->width = 0;
  win->height = 0;
  win->floor_color = 0;
  win->ceiling_color = 0;
  win->have_sprite = 0;
}

void init_map(void)
{
  if (!(map = (t_map *)malloc(sizeof(t_map))))
    exit_game("Error\nMemory allocation error\n");
  map->map_str = NULL;
  map->map_name = "Cub3D";
  map->width = 0;
  map->height = 0;
}

void init_key(void)
{

  if (!(g_key = (t_key *)malloc(sizeof(t_key))))
    exit_game("Error\nMemory allocation error\n");
  g_key->toward = 0;
  g_key->backward = 0;
  g_key->left = 0;
  g_key->right = 0;
  g_key->turn_left = 0;
  g_key->turn_right = 0;
  g_key->cam_up = 0;
  g_key->cam_down = 0;
  g_key->exit = 0;
}

void init_player(void)
{
  if (!(player = (t_player *)malloc(sizeof(t_player))))
    exit_game("Error\nMemory allocation error\n");
  player->pos_x = 0;
  player->pos_y = 0;
  player->dir_x = 0.0;
  player->dir_y = 0.0;
  player->plane_x = 0.0;
  player->plane_y = 0.0;
  player->rotate_speed = 0.10;
  player->speed = 0.25;
  player->cam_height = 1.0;
}

void init_img(void)
{
  if (!(img = (t_image *)malloc(sizeof(t_image))))
    exit_game("Error\nMemory allocation error\n");
  img->width = win->width;
  img->height = win->height;
  img->size_line = 0;
  img->bpp = 0;
  img->endian = 0;
}

void init_texture_array(void)
{
  if (!(textures = malloc(sizeof(t_image *) * 4)))
    exit_game("Error\nMemory allocation error\n");
}

void init_texture(char *path, int index)
{
  t_image *new_elem;

  if (!(new_elem = (t_image *)malloc(sizeof(t_image))))
    exit_game("Error\nMemory allocation error\n");
  new_elem->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, path, &new_elem->width, &new_elem->height);
  new_elem->data = mlx_get_data_addr(new_elem->img_ptr, &new_elem->bpp, &new_elem->size_line, &new_elem->endian);
  textures[index] = new_elem;
  if (index == 0)
    config->texture_no = 1;
  else if (index == 1)
    config->texture_so = 1;
  else if (index == 2)
    config->texture_we = 1;
  else if (index == 3)
    config->texture_ea = 1;
  free(path);
}
