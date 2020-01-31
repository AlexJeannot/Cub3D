#include "../includes/second_cube.h"

void init_ray(void)
{
  t_ray	*new_elem;

  new_elem = (t_ray *)malloc(sizeof(t_ray));
  ray = new_elem;
  ray->pix = 0;
  ray->z_buffer = malloc(sizeof(double) * win->width);
}

void init_ray_values(void)
{
  ray->camera_x = (2 * ray->pix) / (double)win->width - 1; //Calcul position de la camera (pour rayon)
  ray->dir_x = win->player->dir_x + win->player->plane_x * ray->camera_x; // Calcul x du rayon
  ray->dir_y = win->player->dir_y + win->player->plane_y * ray->camera_x; // Calcul y du rayon
  ray->mapx = (int)win->player->pos_x; // Position actuelle du rayon sur la map
  ray->mapy = (int)win->player->pos_y; // Position actuelle du rayon sur la map
  ray->delta_dist_x = fabs(1 / ray->dir_x); // Distance pour aller d'un x a un autre
  ray->delta_dist_y = fabs(1 / ray->dir_y); // Distance pour aller d'un y a un autre
  ray->hit = 0; // hit = 0 si pas de mur / hit = 1 si mur
}
