#include "./includes/cub3D.h"

void draw(void)
{
  init_ray();
  while (ray->line_x < win->width)
  {
    /* Calculs des differentes variables */
    init_ray_values();
    calcul_wall_distance();
    find_wall_or_sprite();
    calcul_wall_height();
    calcul_wall_ordinate();
    calcul_wall_x();

    /* Mise a jour de donnes de la fenetre */
    display_vertical_color(win->floor_color, 0, ray->draw_start);
    display_vertical_texture(ray->draw_start, ray->draw_end);
    display_vertical_color(win->ceiling_color, ray->draw_end, win->height);

    ray->line_x++;
  }
  diplay_sprite(); // Affichage des sprites un fois le decor affiché
  if (win->save == 0) // Si pas d'argument save alors mise a jour de la fenetre
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
  else if (win->save == 1) // Autrement cretion du screenshot au format .bmp
    create_bitmap();
  free(ray->z_buffer);
  ray->z_buffer = NULL;
  free(ray);
  ray = NULL;
  free_diplayed_sprites(); // Free des sprites affichés

}

int loop(void)
{
  draw();
  key_manager();
  return (1);
}

int main(int argc, char **argv)
{
  /* Debut de l'initialisation des differentes structures */
  init_win(argc, argv);
  init_map();
  init_key();
  init_player();
  init_img();
  init_texture_array();
  parse_config(argv[1]); // Parsing du fichier de configuration, check des potentielles erreurs et setting des variables
  set_win_and_img();
  /* Fin de l'initialisation des differentes structures */
  /* Debut de l'initialisation des differents events */
  mlx_hook(win->win_ptr, 2, 0, key_pressed, win);
  mlx_hook(win->win_ptr, 3, 0, key_released, win);
  mlx_hook(win->win_ptr, 17, 0, end_game, win);
  mlx_loop_hook(win->mlx_ptr, loop, win);
  mlx_loop(win->mlx_ptr); // Lancement de la boucle

}
