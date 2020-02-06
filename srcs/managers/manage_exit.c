#include "../../includes/cub3D.h"

void free_textures(void)
{
  int cmp;

  cmp = 0;
  if (textures)
  {
    while (cmp < 4)
    {
      free(textures[cmp]);
      cmp++;
    }
    free(textures);
  }
}

void free_elements(void)
{
  int cmp;

  cmp = 0;
  if (win)
    free(win);
  while (cmp < map->height)
  {
    if (map->map_array[cmp])
      free(map->map_array[cmp]);
    cmp++;
  }
  if (map->map_array)
    free(map->map_array);
  if (map)
    free(map);
  if (g_key)
    free(g_key);
  if (player)
    free(player);
  if (img)
    free(img);
  if (ray && ray->z_buffer)
    free(ray->z_buffer);
  if (ray)
    free(ray);
  if (s_texture)
    free(s_texture);
  if (s_draw)
    free(s_draw);
  if (config)
    free(config);
  free_diplayed_sprites();
  free_textures();
}

void exit_game(char *str)
{
  int cmp;

  cmp = 0;
  if (str)
  {
      while (str[cmp])
      {
        write(1, &str[cmp], 1);
        cmp++;
      }
  }
  if (win && win->mlx_ptr && win->win_ptr)
    mlx_destroy_window(win->mlx_ptr, win->win_ptr);
  free_elements();
  exit(1);
}
