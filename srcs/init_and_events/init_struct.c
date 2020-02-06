#include "../../includes/cub3D.h"

/* Initialisation de la structure windows */
void init_win(int argc, char **argv)
{
  if (!(win = (t_win *)malloc(sizeof(t_win))))
    exit_game("Error\nMemory allocation error\n");
  win->mlx_ptr = mlx_init();
  win->width = 0;
  win->height = 0;
  win->floor_color = 0;
  win->ceiling_color = 0;
  win->have_sprite = 0;

  if (argc >= 3) // Check si argument -save renseigné lors de l'execution du programme
  {
    if (argv[2][0] == '-' && argv[2][1] == 's' && argv[2][2] == 'a' && argv[2][3] == 'v' && argv[2][4] == 'e')
      win->save = 1;
    else
      win->save = 0;
  }
}

/* Initialisation de la structure map */
void init_map(void)
{
  if (!(map = (t_map *)malloc(sizeof(t_map))))
    exit_game("Error\nMemory allocation error\n");
  map->map_str = NULL;
  map->map_name = "Cub3D";
  map->width = 0;
  map->height = 0;
}

/* Initialisation de la structure key */
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

/* Initialisation de la structure player */
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

/* Initialisation de la structure img */
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
