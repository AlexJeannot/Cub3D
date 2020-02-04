#include "./includes/cub3D.h"

void draw(void)
{
  init_ray();
  while (ray->line_x < win->width)
  {
    init_ray_values();
    calcul_wall_distance();
    find_wall_or_sprite();
    calcul_wall_height();
    calcul_wall_ordinate();
    calcul_wall_x();
    display_vertical_color(win->floor_color, 0, ray->draw_start);
    display_vertical_texture(ray->draw_start, ray->draw_end);
    display_vertical_color(win->ceiling_color, ray->draw_end, win->height);

    ray->line_x++;
  }
  diplay_sprite();
  mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
  free(ray->z_buffer);
  ray->z_buffer = NULL;
  free(ray);
  ray = NULL;
  free_diplayed_sprites();

}

int loop(void)
{
  draw();
  key_manager();
  return (1);
}

int main(int argc, char **argv)
{
  (void)argc;
  init_win();
  init_map();
  init_key();
  init_player();
  init_img();
  init_texture_array();
  parse_config(argv[1]);
  win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, "Cub3D");
  img->img_ptr = mlx_new_image(win->mlx_ptr, win->width, win->height);
  img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,	&img->size_line, &img->endian);
  mlx_hook(win->win_ptr, 2, 0, key_pressed, win);
  mlx_hook(win->win_ptr, 3, 0, key_released, win);
  mlx_hook(win->win_ptr, 17, 0, end_game, win);
  mlx_loop_hook(win->mlx_ptr, loop, win);
  mlx_loop(win->mlx_ptr);

}
