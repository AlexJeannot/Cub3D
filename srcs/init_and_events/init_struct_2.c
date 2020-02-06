#include "../../includes/cub3D.h"

/* Initialisation de la structure textures (tableau de structure permettant de stocker les donnnes des differentes textures) */
void init_texture_array(void)
{
  if (!(textures = malloc(sizeof(t_image *) * 4)))
    exit_game("Error\nMemory allocation error\n");
}

/* Initialisation d'une texture via la structure img */
void init_texture(char *path, int index)
{
  t_image *new_elem;

  if (!(new_elem = (t_image *)malloc(sizeof(t_image))))
    exit_game("Error\nMemory allocation error\n");
  new_elem->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, path, &new_elem->width, &new_elem->height);
  new_elem->data = mlx_get_data_addr(new_elem->img_ptr, &new_elem->bpp, &new_elem->size_line, &new_elem->endian);
  textures[index] = new_elem;

  if (index == 0) // Confirmation de l'initialisation de la texture
    config->texture_no = 1;
  else if (index == 1)
    config->texture_so = 1;
  else if (index == 2)
    config->texture_we = 1;
  else if (index == 3)
    config->texture_ea = 1;
  free(path);
}

/* Initialisation de la structure ray (stockant toutes les variables necessaires au raycasting)*/
void init_ray(void)
{
  if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
    exit_game("Error\nMemory allocation error\n");
  ray->line_x = 0;
  if (!(ray->z_buffer = malloc(sizeof(double) * win->width)))
    exit_game("Error\nMemory allocation error\n");
}

/* Initialisation des variables necessaires au raycasting)*/
void init_ray_values(void)
{
  ray->camera_x = (2 * ray->line_x) / (double)win->width - 1; //Calcul position de la camera (pour ray)
  ray->dir_x = player->dir_x + player->plane_x * ray->camera_x; // Calcul x du ray
  ray->dir_y = player->dir_y + player->plane_y * ray->camera_x; // Calcul y du ray
  ray->map_x = (int)player->pos_x; // Position x de depart du ray
  ray->map_y = (int)player->pos_y; // Position y de depart du ray
  ray->delta_dist_x = fabs(1 / ray->dir_x); // Distance pour aller d'un x a un autre
  ray->delta_dist_y = fabs(1 / ray->dir_y); // Distance pour aller d'un y a un autre
  ray->hit = 0; // hit = 0 si pas de mur / hit = 1 si mur
}

/* Creation de la fenetre et de l'image initiale apres le setting de toutes les variables (parsing)*/
void set_win_and_img(void)
{
  win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, "Cub3D");
  img->img_ptr = mlx_new_image(win->mlx_ptr, win->width, win->height);
  img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,	&img->size_line, &img->endian);
}
