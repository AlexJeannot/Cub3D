#include "../includes/cub3D.h"

void			calcul_values(void)
{

	s_draw->inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);

	s_draw->transform_x = s_draw->inv_det * (player->dir_y * s_draw->sprite_x - player->dir_x * s_draw->sprite_y);

	s_draw->transform_y = s_draw->inv_det * (-player->plane_y * s_draw->sprite_x + player->plane_x * s_draw->sprite_y);

	s_draw->sprite_screen_x = (int)((win->width / 2) * (1 + s_draw->transform_x / s_draw->transform_y));

	s_draw->sprite_height = abs((int)(win->height / s_draw->transform_y));

	s_draw->draw_start_y = -s_draw->sprite_height / 2 + ((win->height / 2) * player->cam_height);


  if (s_draw->draw_start_y < 0)
  {
		s_draw->draw_start_y = 0;
  }


	s_draw->draw_end_y = s_draw->sprite_height / 2 + ((win->height / 2) * player->cam_height);


	if (s_draw->draw_end_y >= win->height)
  {
		s_draw->draw_end_y = win->height - 1;
  }


	s_draw->sprite_width = abs((int)(win->height / s_draw->transform_y));

	s_draw->draw_start_x = -s_draw->sprite_width / 2 + s_draw->sprite_screen_x;


	if (s_draw->draw_start_x < 0)
  {
		s_draw->draw_start_x = 0;
  }


	s_draw->draw_end_x = s_draw->sprite_width / 2 + s_draw->sprite_screen_x;


	if (s_draw->draw_end_x >= win->width)
  {
		s_draw->draw_end_x = win->width - 1;
  }


	s_draw->stripe = s_draw->draw_start_x;
}

void			pix_on_sprite_image(void)
{
	s_draw->d = s_draw->y * s_texture->size_line - (win->height * player->cam_height) * (s_texture->size_line / 2) + s_draw->sprite_height * s_texture->size_line / 2;
	s_draw->tex_y = ((s_draw->d * s_texture->height) / s_draw->sprite_height) / s_texture->size_line;
	s_draw->totcolor = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8]
   + s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 1]
   + s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 2];
}

void			is_black(void)
{
	img->data[s_draw->y * img->size_line + s_draw->stripe * img->bpp / 8] = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8];
	img->data[s_draw->y * img->size_line + s_draw->stripe * img->bpp / 8 + 1] = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 1];
	img->data[s_draw->y * img->size_line + s_draw->stripe * img->bpp / 8 + 2] = s_texture->data[s_draw->tex_y * s_texture->size_line + s_draw->tex_x * s_texture->bpp / 8 + 2];
}

void draw_sprite(t_sprite_array *sprite_pos)
{
  s_draw->sprite_x = sprite_pos->x - (player->pos_x - 0.5);
  s_draw->sprite_y = sprite_pos->y - (player->pos_y - 0.5);
  calcul_values();

  while (s_draw->stripe < s_draw->draw_end_x)
	{
		s_draw->tex_x = (int)(s_texture->size_line * (s_draw->stripe - (-s_draw->sprite_width / 2 + s_draw->sprite_screen_x)) * s_texture->width / s_draw->sprite_width) / s_texture->size_line;
		if (s_draw->transform_y > 0 && s_draw->stripe > 0 && s_draw->stripe < win->width && s_draw->transform_y < ray->z_buffer[s_draw->stripe])
		{
			s_draw->y = s_draw->draw_start_y;
			while (s_draw->y < s_draw->draw_end_y)
			{
				pix_on_sprite_image();
				if (s_draw->totcolor != 0)
					is_black();
				s_draw->y++;
			}
		}
		s_draw->stripe++;
	}
}

void diplay_sprite(void)
{
  int cmp;

  cmp = 0;
  if (s_displayable)
  {
    if(!(s_draw = malloc(sizeof(t_draw))))
			exit_game("Error\nMemory allocation error\n");
    if (!(s_array = malloc(sizeof(t_sprite_array *) * (win->have_sprite + 1))))
			exit_game("Error\nMemory allocation error\n");
    sprites_into_array();
    sort_displayable_sprites();
    while (s_array[cmp]->x != -1)
    {
      draw_sprite(s_array[cmp]);
      cmp++;
    }
  }
}
