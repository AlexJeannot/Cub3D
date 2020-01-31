#include "../includes/second_cube.h"

static void			calcul_values()
{

	sp->inv_det = 1.0 / (win->player->plane_x * win->player->dir_y - win->player->dir_x * win->player->plane_y);

	sp->transform_x = sp->inv_det * (win->player->dir_y * sp->sprite_x - win->player->dir_x * sp->sprite_y);

	sp->transform_y = sp->inv_det * (-win->player->plane_y * sp->sprite_x + win->player->plane_x * sp->sprite_y);

	sp->sprite_screen_x = (int)((win->width / 2) * (1 + sp->transform_x / sp->transform_y));

	sp->sprite_height = abs((int)(win->height / sp->transform_y));

	sp->draw_start_y = -sp->sprite_height / 2 + ((win->height / 2) * win->player->cam_height);


  if (sp->draw_start_y < 0)
  {
		sp->draw_start_y = 0;
  }


	sp->draw_end_y = sp->sprite_height / 2 + ((win->height / 2) * win->player->cam_height);


	if (sp->draw_end_y >= win->height)
  {
		sp->draw_end_y = win->height - 1;
  }


	sp->sprite_width = abs((int)(win->height / sp->transform_y));

	sp->draw_start_x = -sp->sprite_width / 2 + sp->sprite_screen_x;


	if (sp->draw_start_x < 0)
  {
		sp->draw_start_x = 0;
  }


	sp->draw_end_x = sp->sprite_width / 2 + sp->sprite_screen_x;


	if (sp->draw_end_x >= win->width)
  {
		sp->draw_end_x = win->width - 1;
  }


	sp->stripe = sp->draw_start_x;
}

static void			pix_on_sprite_image(void)
{
	sp->d = sp->y * win->sprite->size_line - (win->height * win->player->cam_height) * (win->sprite->size_line / 2) + sp->sprite_height * win->sprite->size_line / 2;
	sp->tex_y = ((sp->d * win->sprite->height) / sp->sprite_height) / win->sprite->size_line;
	sp->totcolor = win->sprite->data[sp->tex_y * win->sprite->size_line + sp->tex_x * win->sprite->bpp / 8]
   + win->sprite->data[sp->tex_y * win->sprite->size_line + sp->tex_x * win->sprite->bpp / 8 + 1]
   + win->sprite->data[sp->tex_y * win->sprite->size_line + sp->tex_x * win->sprite->bpp / 8 + 2];
}

static void			is_black(void)
{
	win->img->data[sp->y * win->img->size_line + sp->stripe * win->img->bpp / 8] = win->sprite->data[sp->tex_y * win->sprite->size_line + sp->tex_x * win->sprite->bpp / 8];
	win->img->data[sp->y * win->img->size_line + sp->stripe * win->img->bpp / 8 + 1] = win->sprite->data[sp->tex_y * win->sprite->size_line + sp->tex_x * win->sprite->bpp / 8 + 1];
	win->img->data[sp->y * win->img->size_line + sp->stripe * win->img->bpp / 8 + 2] = win->sprite->data[sp->tex_y * win->sprite->size_line + sp->tex_x * win->sprite->bpp / 8 + 2];
}

void draw_sprite(t_sprite_list *sprite_pos)
{
  sp->sprite_x = sprite_pos->x - (win->player->pos_x - 0.5);
  sp->sprite_y = sprite_pos->y - (win->player->pos_y - 0.5);
  calcul_values();

  while (sp->stripe < sp->draw_end_x)
	{
		sp->tex_x = (int)(win->sprite->size_line * (sp->stripe - (-sp->sprite_width / 2 + sp->sprite_screen_x)) * win->sprite->width / sp->sprite_width) / win->sprite->size_line;
		if (sp->transform_y > 0 && sp->stripe > 0 && sp->stripe < win->width && sp->transform_y < ray->z_buffer[sp->stripe])
		{
			sp->y = sp->draw_start_y;
			while (sp->y < sp->draw_end_y)
			{
				pix_on_sprite_image();
				if (sp->totcolor != 0)
					is_black();
				sp->y++;
			}
		}
		sp->stripe++;
	}
}

void diplay_sprite(void)
{
  int cmp;

  cmp = 0;
  if (win->displayable_sprite)
  {
    sp = malloc(sizeof(t_draw_sprites));
    sp->sprite_list = malloc(sizeof(t_sprite_list *) * (win->have_sprite + 1));
    into_list();
    sort_displayable_sprites();
    while (sp->sprite_list[cmp]->x != -1)
    {
      draw_sprite(sp->sprite_list[cmp]);
      cmp++;
    }
  }
}
