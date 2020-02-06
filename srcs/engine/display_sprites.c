#include "../../includes/cub3D.h"

void			calcul_values(void)
{

	s_draw->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y); // coefficient de tranformation par rapport a la camera
	s_draw->transform_x = s_draw->inv_det * (player->dir_y * s_draw->sprite_x - player->dir_x * s_draw->sprite_y);
	s_draw->transform_y = s_draw->inv_det * (-player->plane_y * s_draw->sprite_x + player->plane_x * s_draw->sprite_y);

	s_draw->sprite_screen_x = (int)((win->width / 2) * (1 + s_draw->transform_x / s_draw->transform_y));
	s_draw->sprite_height = abs((int)(win->height / s_draw->transform_y));

	s_draw->start_y = -s_draw->sprite_height / 2 + ((win->height / 2) * player->cam_height); // Definition debut du y
  if (s_draw->start_y < 0)
		s_draw->start_y = 0;

	s_draw->end_y = s_draw->sprite_height / 2 + ((win->height / 2) * player->cam_height); // Definition fin du y
	if (s_draw->end_y >= win->height)
		s_draw->end_y = win->height - 1;

	s_draw->sprite_width = abs((int)(win->height / s_draw->transform_y));

	s_draw->start_x = -s_draw->sprite_width / 2 + s_draw->sprite_screen_x; // Definition debut du x
	if (s_draw->start_x < 0)
		s_draw->start_x = 0;

	s_draw->end_x = s_draw->sprite_width / 2 + s_draw->sprite_screen_x; // Definition fin du x
	if (s_draw->end_x >= win->width)
		s_draw->end_x = win->width - 1;
}

void			pix_on_sprite_image(void)
{
	s_draw->coef = s_draw->y * s_texture->size_line - (win->height * player->cam_height) * (s_texture->size_line / 2) + s_draw->sprite_height * s_texture->size_line / 2;
	s_draw->tex_y = ((s_draw->coef * s_texture->height) / s_draw->sprite_height) / s_texture->size_line;
	s_draw->pix_color = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8] // calcul de la valeur RGB
   + s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 1]
   + s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 2];
}

void			pix_to_be_diplay(void)
{
	img->data[s_draw->y * img->size_line + s_draw->start_x * img->bpp / 8] = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8];
	img->data[s_draw->y * img->size_line + s_draw->start_x * img->bpp / 8 + 1] = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 1];
	img->data[s_draw->y * img->size_line + s_draw->start_x * img->bpp / 8 + 2] = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 2];
}

void draw_sprite(t_sprite_array *sprite_pos)
{
  s_draw->sprite_x = sprite_pos->x - (player->pos_x - 0.5); // position x relative du sprite par rapport au joueur
  s_draw->sprite_y = sprite_pos->y - (player->pos_y - 0.5); // position y relative du sprite par rapport au joueur
  calcul_values();

  while (s_draw->start_x < s_draw->end_x)
	{
		s_draw->tex_x = (int)(s_texture->size_line * (s_draw->start_x - (-s_draw->sprite_width / 2 + s_draw->sprite_screen_x)) * s_texture->width / s_draw->sprite_width) / s_texture->size_line;
		if (s_draw->transform_y > 0 && s_draw->start_x > 0 && s_draw->start_x < win->width && s_draw->transform_y < ray->z_buffer[s_draw->start_x])
		{
			s_draw->y = s_draw->start_y;
			while (s_draw->y < s_draw->end_y)
			{
				pix_on_sprite_image();
				if (s_draw->pix_color != 0) // Si la valeur RGB = 0 alors pixel noir et ne pas a afficher
					pix_to_be_diplay();
				s_draw->y++;
			}
		}
		s_draw->start_x++;
	}
}

void diplay_sprite(void)
{
  int cmp;

  cmp = 0;
  if (s_displayable) // Si le premier pointeur de la liste chaine n'est pas NULL
  {
    if(!(s_draw = malloc(sizeof(t_draw))))
			exit_game("Error\nMemory allocation error\n");
    if (!(s_array = malloc(sizeof(t_sprite_array *) * (win->have_sprite + 1))))
			exit_game("Error\nMemory allocation error\n");
    sprites_into_array(); // Transformation des elements de la liste chainé en tableau de structures
    sort_displayable_sprites(); // Tri des sprites du plus loin au plus pres
    while (s_array[cmp]->x != -1)
    {
      draw_sprite(s_array[cmp]); // Affichage des sprites du plus loin au plus pres
      cmp++;
    }
  }
}
