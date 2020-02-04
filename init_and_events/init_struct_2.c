#include "../includes/cub3D.h"

void init_ray(void)
{
  if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
    exit_game("Error\nMemory allocation error\n");
  ray->line_x = 0;
  if (!(ray->z_buffer = malloc(sizeof(double) * win->width)))
    exit_game("Error\nMemory allocation error\n");
}

void init_ray_values(void)
{
  ray->camera_x = (2 * ray->line_x) / (double)win->width - 1; //Calcul position de la camera (pour ray)
  ray->dir_x = player->dir_x + player->plane_x * ray->camera_x; // Calcul x du ray
  ray->dir_y = player->dir_y + player->plane_y * ray->camera_x; // Calcul y du ray
  ray->map_x = (int)player->pos_x; // Position actuelle du ray sur la map
  ray->map_y = (int)player->pos_y; // Position actuelle du ray sur la map
  ray->delta_dist_x = fabs(1 / ray->dir_x); // Distance pour aller d'un x a un autre
  ray->delta_dist_y = fabs(1 / ray->dir_y); // Distance pour aller d'un y a un autre
  ray->hit = 0; // hit = 0 si pas de mur / hit = 1 si mur
}
