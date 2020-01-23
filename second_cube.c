#include "second_cube.h"

void init(void)
{
  printf("- PRE MLX_PTR -\n");
  win->mlx_ptr = mlx_init();
  printf("- PRE WIDTH -\n");
  win->width = 640;
  printf("- PRE HEIGHT -\n");
  win->height = 480;
  printf("- PRE FLOOR -\n");
  win->floor_color = 9224898;
  printf("- PRE CEILING -\n");
  win->ceiling_color = 13916505;
  win->wall_color = 13922558;
  printf("- PRE WIN_PTR -\n");
  win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, "TEST_WIN");
  printf("- POST WIN_PTR -\n");
}

void init_map(void)
{
  t_map	*new_elem;

  new_elem = (t_map *)malloc(sizeof(t_map));
  win->map = new_elem;

  char **str_map;
  char *str_1;
  char *str_2;
  char *str_3;
  char *str_4;
  char *str_5;
  char *str_6;

  str_1 = malloc(sizeof(char) * 11);
  str_2 = malloc(sizeof(char) * 11);
  str_3 = malloc(sizeof(char) * 11);
  str_4 = malloc(sizeof(char) * 11);
  str_5 = malloc(sizeof(char) * 11);
  str_6 = malloc(sizeof(char) * 11);

  str_map = malloc((sizeof(char*) * 6)); // + (sizeof(char) * 66)

  str_1 = "1111111111";
  str_2 = "1000000001";
  str_3 = "1000010001";
  str_4 = "1000010001";
  str_5 = "1000000001";
  str_6 = "1111111111";

  str_map[0] = str_1;
  str_map[1] = str_2;
  str_map[2] = str_3;
  str_map[3] = str_4;
  str_map[4] = str_5;
  str_map[5] = str_6;

  win->map->map = str_map;
  win->map->map_name = "TEST";
  win->map->width = 10;
  win->map->height = 6;
}

void init_keybuffer(void)
{
  t_keybuffer	*new_elem;

  new_elem = (t_keybuffer *)malloc(sizeof(t_keybuffer));
  win->keybuffer = new_elem;

  win->keybuffer->toward = 0;
  win->keybuffer->backward = 0;
  win->keybuffer->left = 0;
  win->keybuffer->right = 0;
  win->keybuffer->turn_left = 0;
  win->keybuffer->turn_right = 0;
  win->keybuffer->cam_up = 0;
  win->keybuffer->cam_down = 0;
}

void init_player(void)
{
  t_player	*new_elem;

  new_elem = (t_player *)malloc(sizeof(t_player));
  win->player = new_elem;

  win->player->pos_x = 8.0;
  win->player->pos_y = 4.0;
  win->player->dir_x = -1.0;
  win->player->dir_y = 0.0;
  win->player->plane_x = 0.00;
  win->player->plane_y = 0.66;
//  win->player->rotate_speed = ;
//  win->player->speed = ;
  win->player->cam_height = 1.0;
//  win->player->health = ;
}

void init_image(void)
{
  t_image	*new_elem;

  new_elem = (t_image *)malloc(sizeof(t_image));
  win->img = new_elem;

  win->img->img_ptr = mlx_new_image(win->mlx_ptr, win->width, win->height);
  win->img->width = win->width;
  win->img->height = win->height;
  win->img->size_line = 0;
  win->img->bpp = 0;
  win->img->endian = 0;
  win->img->data = mlx_get_data_addr(win->img->img_ptr, &win->img->bpp,	&win->img->size_line, &win->img->endian);
}

static void	determine_side_draw(/*t_line *line, double wall_x*/)
{
	int		tex_x;

/*	img = win->textures[3];
	if (ray->side == 1)
		img = win->textures[2];
	if (ray->side == 2)
		img = win->textures[1];
	if (ray->side == 3)
		img = win->textures[0];*/
  tex_x = (int)(wall_x * (double)win->img->width);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		tex_x = win->img->width - tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		tex_x = win->img->width - tex_x - 1;
	line->y0 = ray->draw_end;
	line->y1 = ray->draw_start;
	line->tex_x = tex_x;
//	ver_line_texture_image(line, win, img, ray);
}


void		pixel_put_to_image(int color,/* int x,*/ int y/*, t_image *img*/)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	win->img->data[y * win->img->size_line + line->x * win->img->bpp / 8] = r;
	win->img->data[y * win->img->size_line + line->x * win->img->bpp / 8 + 1] = g;
	win->img->data[y * win->img->size_line + line->x * win->img->bpp / 8 + 2] = b;
}


/*void		ver_line_color_image(/*t_line *line, int color)
{

}*/


/*static void	texture_on_img(
	t_line *line,
	t_image *texture,
	t_window *win_infos,
	t_ray *ray
)
{
	int d;

	d = line->y * texture->size_line - (win_infos->height
		* win_infos->player->cam_height) * texture->size_line
		/ 2 + ray->line_height * texture->size_line / 2;
	line->tex_y = ((d * texture->height) / ray->line_height)
		/ texture->size_line;
	win_infos->img->data[line->y * win_infos->img->size_line + line->x
					* win_infos->img->bpp / 8] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)];
	win_infos->img->data[line->y * win_infos->img->size_line + line->x
					* win_infos->img->bpp / 8 + 1] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 1];
	win_infos->img->data[line->y * win_infos->img->size_line + line->x
					* win_infos->img->bpp / 8 + 2] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 2];
}



void		ver_line_texture_image(
	t_line *line,
	t_window *win_infos,
	t_image *texture,
	t_ray *ray
)
{
	int y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			texture_on_img(line, texture, win_infos, ray);
			line->y++;
		}
	}
}*/



void draw()
{
  t_ray	*new_elem;

  new_elem = (t_ray *)malloc(sizeof(t_ray));
  ray = new_elem;
  ray->pix = 0;

  //ray->z_buffer = malloc(sizeof(double) * win->width);

  //do_raycasting
//  printf("ray->pix = %d\n", ray->pix);

  while (ray->pix < win->width)
  {
    printf("----- START WHILE -----\n\n");
    //init_values
  //  printf("ray->pix = %d\n", ray->pix);
  //  printf("win->width = %d\n", win->width);
    ray->camera_x = (2 * ray->pix) / (double)win->width - 1; //Calcul position de la camera (pour rayon)
  	ray->ray_dir_x = win->player->dir_x + win->player->plane_x * ray->camera_x; // Calcul x du rayon
  	ray->ray_dir_y = win->player->dir_y + win->player->plane_y * ray->camera_x; // Calcul y du rayon
  	ray->mapx = (int)win->player->pos_x; // Position actuelle sur la map
  	ray->mapy = (int)win->player->pos_y; // Position actuelle sur la map
  	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
  	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
  	ray->hit = 0;

  //  printf("ray->mapx = %d\n", ray->mapx);

    if (ray->ray_dir_x < 0)
      {
      //  printf("ENTER IF 1\n");
        ray->step_x = -1;
        ray->side_dist_x = (win->player->pos_x - ray->mapx) * ray->delta_dist_x;
      }
      else
      {
    //    printf("ENTER IF 2\n");
        ray->step_x = 1;
        ray->side_dist_x = (ray->mapx + 1.0 - win->player->pos_x) * ray->delta_dist_x;
      }
      if (ray->ray_dir_y < 0)
      {
    //    printf("ENTER IF 3\n");
        ray->step_y = -1;
        ray->side_dist_y = (win->player->pos_y - ray->mapy) * ray->delta_dist_y;
      }
      else
      {
      //  printf("ENTER IF 4\n");
        ray->step_y = 1;
        ray->side_dist_y = (ray->mapy + 1.0 - win->player->pos_y) * ray->delta_dist_y;
      }
  //  printf("STEP 0\n");
    while (ray->hit == 0)
    {
      //jump to next map square, OR in x-direction, OR in y-direction
    //  printf("--- START BOUCLE ---\n");
    //  printf("ray->side_dist_x = %f\nray->side_dist_y = %f\n", ray->side_dist_x, ray->side_dist_y);
    //  printf("ray->mapx = %d\nray->mapy = %d\n", ray->mapx, ray->mapy);
      if (ray->side_dist_x < ray->side_dist_y)
      {
    //    printf("PASSE IF\n");
        ray->side_dist_x += ray->delta_dist_x;
        ray->mapx += ray->step_x;
        ray->side = 0;
      }
      else
      {
      //  printf("PASSE ELSE\n");
        ray->side_dist_y += ray->delta_dist_y;
        ray->mapy += ray->step_y;
        ray->side = 1;
      }
      //Check if ray has hit a wall
      //printf("ray->mapx = %d\nray->mapy = %d\n", ray->mapx, ray->mapy);
      if (win->map->map[ray->mapy][ray->mapx] > 0)
        ray->hit = 1;
      //  printf("--- FIN BOUCLE ---\n");
    }
    //printf("SORTIE BOUCLE\n");
    //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
    if (ray->side == 0)
      ray->perp_wall_dist = (ray->mapx - win->player->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
      ray->perp_wall_dist = (ray->mapy - win->player->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;


    //Calculate height of line to draw on screen
     ray->line_height = (int)(win->height / ray->perp_wall_dist);

     //calculate lowest and highest pixel to fill in current stripe
     ray->draw_start = -ray->line_height / 2 + win->height / 2;
     if(ray->draw_start < 0)
     {
       ray->draw_start = 0;
     }

     ray->draw_end = -ray->line_height / 2 + win->height / 2;
     if(ray->draw_end >= win->height)
     {
       ray->draw_end = win->height - 1;
     }

     printf("END INIT\ndraw_start = %d\ndraw_end = %d\n", ray->draw_start, ray->draw_end);





























    //???
    //printf("- PRE ay->z_buffer -\n");
    //ray->z_buffer[ray->pix] = ray->perp_wall_dist;
    //printf("- POST ay->z_buffer -\n");
    //texturisation
    t_line	*new_line;
    new_line = (t_line *)malloc(sizeof(t_line *));
    line = new_line;


    line->x = ray->pix;
  	if (ray->side == 0 || ray->side == 1)
    {
  		wall_x = win->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
    }
  	else
    {
  		wall_x = win->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
    }
  	wall_x -= floor(wall_x);
    /*if (win->map->map[ray->mapy][ray->mapx] == '1')
      {
    		determine_side_draw(line, wall_x);
      }*/
  	line->y0 = 0;
  	line->y1 = ray->draw_start;


    printf("-- START DRAW 1 --\nline->y0 = %d\nline->y1 = %d\n", line->y0, line->y1);




// ver_line_color_image   win->ceiling_color

    int y;
    int y_max;

    if (line->y0 < line->y1)
    {
      y = line->y0;
      y_max = line->y1;
    }
    else
    {
      y = line->y1;
      y_max = line->y0;
    }
    if (y >= 0)
    {
      while (y < y_max)
      {
        pixel_put_to_image(win->ceiling_color,/* line->x, */y/*, win->img*/);
        y++;
      }
    }

    printf("-- END DRAW 1 --\nline->y0 = %d\nline->y1 = %d\n-- END DRAW 1 --\n\n", line->y0, line->y1);
  //	ver_line_color_image(/*line, */win->ceiling_color);






  	line->y0 = win->height;
  	line->y1 = ray->draw_end;

    printf("-- START DRAW 2 --\nline->y0 = %d\nline->y1 = %d\n", line->y0, line->y1);


// ver_line_color_image   win->ceiling_color


    int y2;
    int y2_max;

    if (line->y0 < line->y1)
    {
      y2 = line->y0;
      y2_max = line->y1;
    }
    else
    {
      y2 = line->y1;
      y2_max = line->y0;
    }
    if (y2 >= 0)
    {
      while (y2 < y2_max)
      {
        pixel_put_to_image(win->floor_color,/* line->x, */y2/*, win->img*/);
        y2++;
      }
    }


    printf("-- END DRAW 2 --\nline->y0 = %d\nline->y1 = %d\n-- END DRAW 2 --\n\n", line->y0, line->y1);

  	//ver_line_color_image(/*line, */win->floor_color);




    ray->pix++;
    free(line);
    printf("----- END WHILE -----\n\n");
  }
  mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img_ptr, 0, 0);
  free(ray);
  //free(ray->z_buffer);

}

int loop(/*void *param*/)
{
  //t_win *test;

	//test = (t_win *)param;
  draw();
  return (1);
}

int main()
{
  t_win	*new_elem;

	if (!(new_elem = (t_win *)malloc(sizeof(t_win))))
		return (0);
  win = new_elem;
  printf("--- PRE INIT ---\n");
  init();
  printf("--- POST INIT ---\n");
  init_map();
  printf("--- POST INIT MAP ---\n");
  init_keybuffer();
  printf("--- POST INIT KEYBUFFER ---\n");
  init_player();
  printf("--- POST INIT PLAYER ---\n");
  init_image();
  printf("--- POST INIT IMAGE ---\n");

  //draw();
  //printf("--- POST DRAW ---\n");

  //mlx_loop(win->mlx_ptr);
  mlx_loop_hook(win->mlx_ptr, loop, win);
  printf("- POST LOOP HOOK -\n");
  mlx_loop(win->mlx_ptr);
  printf("- POST LOOP -\n");
  printf("--- POST MLX LOOP ---\n");
  system("leaks a.out");
}
