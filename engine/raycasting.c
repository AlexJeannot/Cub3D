#include "../includes/second_cube.h"

void calcul_wall_distance(void)
{
  // Calcul du side_dist_x et side_dist_y => Distance du point initial jusqu'au prochain x/y
  // Set de la direction dans laquelle envoyer le rayon 1 (droite) ou -1 (gauche) pour step_x et step_y
  if (ray->dir_x < 0)
  {
    ray->step_x = -1;
    ray->side_dist_x = (win->player->pos_x - ray->mapx) * ray->delta_dist_x;
  }
  else
  {
    ray->step_x = 1;
    ray->side_dist_x = (ray->mapx + 1.0 - win->player->pos_x) * ray->delta_dist_x;
  }

  if (ray->dir_y < 0)
  {
    ray->step_y = -1;
    ray->side_dist_y = (win->player->pos_y - ray->mapy) * ray->delta_dist_y;
  }
  else
  {
    ray->step_y = 1;
    ray->side_dist_y = (ray->mapy + 1.0 - win->player->pos_y) * ray->delta_dist_y;
  }
}

void find_wall_or_sprite(void)
{
  while (ray->hit == 0) // Tant que hit == 0 alors on continue
  {
    // Predict wall face
    if (ray->side_dist_x < ray->side_dist_y)
    {
      ray->side_dist_x += ray->delta_dist_x;
      ray->mapx += ray->step_x;
      if (ray->step_x == 1)
        ray->side = 0;
      else if (ray->step_x == -1)
        ray->side = 1;
    }
    else
    {
      ray->side_dist_y += ray->delta_dist_y;
      ray->mapy += ray->step_y;
      if (ray->step_y == 1)
        ray->side = 2;
      else if (ray->step_y == -1)
        ray->side = 3;
    }

    if (win->my_map->map[ray->mapy][ray->mapx] == '1')
    { // Check si la nouvelle position du rayon est en contact avec un mur
      ray->hit = 1;
    }
    else if (win->my_map->map[ray->mapy][ray->mapx] == '2')
    {
      add_displayable_sprite();
    }
  }
}


void calcul_wall_height(void)
{
  // Calcul de la hauteur des murs via calcul de la distance entre la position du joueur et celle du mur
  if (ray->side == 0 || ray->side == 1) // Si mur x rencontré
  {
    ray->perp_wall_dist = (ray->mapx - win->player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x; // ray->mapx - win->player->pos_x => cacul entre position initial du rayon (position du joueur) et position finale
  }
  else // Si mur y rencontré
  {
    ray->perp_wall_dist = (ray->mapy - win->player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y; // (ray->mapy - win->player->pos_y + (1 - ray->step_y) / 2) => Nombre de fois que le rayon a croise de y avant de taper le mur
  }

  ray->z_buffer[ray->pix] = ray->perp_wall_dist;

  // Calcul de la hauteur du mur
  ray->wall_height = (int)(win->height / ray->perp_wall_dist);
}

void calcul_wall_ordinate(void)
{
  // Calcul du premier pixel et du dernier pixel a dessiner pour le mur
  ray->draw_start = (-ray->wall_height / 2) + (win->height / 2);
  if(ray->draw_start < 0)
  {
    ray->draw_start = 0;
  }
  ray->draw_end = (ray->wall_height / 2) + (win->height / 2);
  if(ray->draw_end >= win->height)
  {
    ray->draw_end = win->height - 1;
  }
}

void calcul_wall_x(void)
{

  //where exactly the wall was hit
  if (ray->side == 0 || ray->side == 1)
    ray->wall_x = win->player->pos_y + ray->perp_wall_dist * ray->dir_y;
  else
    ray->wall_x = win->player->pos_x + ray->perp_wall_dist * ray->dir_x;
  ray->wall_x -= floor((ray->wall_x));

}
