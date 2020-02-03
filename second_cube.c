#include "includes/second_cube.h"

void draw(void)
{

  init_ray();
  /*
  new_elem = (t_ray *)malloc(sizeof(t_ray));
  ray = new_elem;
  ray->pix = 0;
  ray->z_buffer = malloc(sizeof(double) * win->width);
  */

  while (ray->pix < win->width)
  {




    init_ray_values();
    /*
    ray->camera_x = (2 * ray->pix) / (double)win->width - 1; //Calcul position de la camera (pour rayon)
  	ray->dir_x = win->player->dir_x + win->player->plane_x * ray->camera_x; // Calcul x du rayon
  	ray->dir_y = win->player->dir_y + win->player->plane_y * ray->camera_x; // Calcul y du rayon
  	ray->mapx = (int)win->player->pos_x; // Position actuelle du rayon sur la map
  	ray->mapy = (int)win->player->pos_y; // Position actuelle du rayon sur la map
  	ray->delta_dist_x = fabs(1 / ray->dir_x); // Distance pour aller d'un x a un autre
  	ray->delta_dist_y = fabs(1 / ray->dir_y); // Distance pour aller d'un y a un autre
  	ray->hit = 0; // hit = 0 si pas de mur / hit = 1 si mur
    */




    calcul_wall_distance();
    /*
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
    */






    find_wall_or_sprite();
    /*
    // Algo afin de trouver le mur
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
    */





    calcul_wall_height();
    /*
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
    */






    calcul_wall_ordinate();
    /*
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
    */








      calcul_wall_x();
      /*
      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if (ray->side == 0 || ray->side == 1)
        wallX = win->player->pos_y + ray->perp_wall_dist * ray->dir_y;
      else
        wallX = win->player->pos_x + ray->perp_wall_dist * ray->dir_x;
      wallX -= floor((wallX));
      */




      // Affichage sol
    vert(win->floor_color, 0, ray->draw_start);

      // Affichage murs
    vert_tex(ray->draw_start, ray->draw_end);

      // Affichage plafond
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
  printf("ENTREE ENFIN\n");
  (void)argc;
  init();

  init_map();

  init_keybuffer();

  init_player();

  init_image();

  init_texture_array();
  printf("AVANT PARSE CONFIG\n");
  parse_config(argv[1]);
  printf("APRES PARSE CONFIG\n");
  /*init_texture("./textures/bluestone.xpm", 64, 64); // nord
  init_texture("./textures/eagle.xpm", 64, 64);// sud
  init_texture("./textures/mossy.xpm", 64, 64); // ouest
  init_texture("./textures/purplestone.xpm", 64, 64); // est*/

  //init_sprite();

  mlx_hook(win->win_ptr, 2, 0, key_pressed, win);
  mlx_hook(win->win_ptr, 3, 0, key_released, win);
  mlx_hook(win->win_ptr, 17, 0, end_game, win);

  mlx_loop_hook(win->mlx_ptr, loop, win);

  mlx_loop(win->mlx_ptr);

}
