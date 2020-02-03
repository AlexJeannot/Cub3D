#include "includes/second_cube.h"

void draw(void)
{

  init_ray();

  while (ray->pix < win->width)
  {
    init_ray_values();
    calcul_wall_distance();
    find_wall_or_sprite();
    calcul_wall_height();
    calcul_wall_ordinate();
    calcul_wall_x();

    vert(win->floor_color, 0, ray->draw_start);
    vert_tex(ray->draw_start, ray->draw_end);
    vert(win->ceiling_color, ray->draw_end, win->height);

    ray->pix++;
  }
  diplay_sprite();
  mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img_ptr, 0, 0);
  free(ray);
  free(ray->z_buffer);
  delete_diplayed_sprites();

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
  init();
  init_map();
  init_keybuffer();
  init_player();
  init_image();
  init_texture_array();
  parse_config(argv[1]);
  mlx_hook(win->win_ptr, 2, 0, key_pressed, win);
  mlx_hook(win->win_ptr, 3, 0, key_released, win);
  mlx_hook(win->win_ptr, 17, 0, end_game, win);
  mlx_loop_hook(win->mlx_ptr, loop, win);
  mlx_loop(win->mlx_ptr);

}
