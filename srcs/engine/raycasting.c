#include "../../includes/cub3D.h"

void calcul_wall_distance(void)
{
  // Calcul du side_dist_x et side_dist_y => Distance du point initial jusqu'au prochain x/y
  // Set de la direction dans laquelle envoyer le ray 1 (droite) ou -1 (gauche) pour step_x et step_y
  if (ray->dir_x < 0)
  {
    ray->step_x = -1;
    ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
  }
  else
  {
    ray->step_x = 1;
    ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
  }

  if (ray->dir_y < 0)
  {
    ray->step_y = -1;
    ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
  }
  else
  {
    ray->step_y = 1;
    ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
  }
}

void find_wall_or_sprite(void)
{
  while (ray->hit == 0) // Tant que hit == 0 alors on continue
  {
    if (ray->side_dist_x < ray->side_dist_y) // Incrementation de la distance la plus faible
    {
      ray->side_dist_x += ray->delta_dist_x;
      ray->map_x += ray->step_x;
      if (ray->step_x == 1) // Si vers face ouest
        ray->side = 0;
      else if (ray->step_x == -1) // Si vers face est
        ray->side = 1;
    }
    else
    {
      ray->side_dist_y += ray->delta_dist_y;
      ray->map_y += ray->step_y;
      if (ray->step_y == 1)  // Si vers face sud
        ray->side = 2;
      else if (ray->step_y == -1)  // Si vers face nord
        ray->side = 3;
    }
    /* Check si la nouvelle position du ray est en contact avec un mur ou un sprite */
    if (map->map_array[ray->map_y][ray->map_x] == '1')
      ray->hit = 1;
    else if (map->map_array[ray->map_y][ray->map_x] == '2')
      add_displayable_sprite();
  }
}


void calcul_wall_height(void)
{
  // Calcul de la hauteur des murs via calcul de la distance entre la position du joueur et celle du mur
  if (ray->side == 0 || ray->side == 1) // Si mur x rencontré
    ray->perp_wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x; // ray->map_x - player->pos_x => cacul entre position initial du ray (position du joueur) et position finale
  else
    ray->perp_wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;

  ray->z_buffer[ray->line_x] = ray->perp_wall_dist; // Ajout de la distance dans un tableau de double avant pour index le pixel vertical

  ray->wall_height = (int)(win->height / ray->perp_wall_dist); // Calcul de la hauteur du mur
}

void calcul_wall_ordinate(void)
{
  // Calcul du premier pixel et du dernier pixel a dessiner pour le mur
  ray->draw_start = (-ray->wall_height / 2) + (win->height / 2); // Moitié inferieur du mur + moitie du nombre de pixel en hauteur
  if(ray->draw_start < 0)
    ray->draw_start = 0;
  ray->draw_end = (ray->wall_height / 2) + (win->height / 2); // Moitié superieur du mur + moitie du nombre de pixel en hauteur
  if(ray->draw_end >= win->height)
    ray->draw_end = win->height - 1;
}

void calcul_wall_x(void)
{
  // calcul de l'endroit precis où le mur est frappé
  if (ray->side == 0 || ray->side == 1)
    ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
  else
    ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
  ray->wall_x -= floor((ray->wall_x));

}
