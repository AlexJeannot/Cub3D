#include "../includes/second_cube.h"

void	texture_on_img(int x, int y)
{
	int d;
  int tex_y;
  t_image *text;

  if (ray->side == 0)
    text = win->textures[3];
  else if (ray->side == 1)
    text = win->textures[2];
  else if (ray->side == 2)
    text = win->textures[1];
  else
    text = win->textures[0];

  int tex_x;
  tex_x = (int)(ray->wall_x * (double)text->width);


  d = y * text->size_line - (win->height * win->player->cam_height) * text->size_line / 2 + ray->wall_height * text->size_line / 2;
  tex_y = ((d * text->height) / ray->wall_height) / text->size_line;

  win->img->data[y * win->img->size_line + x * win->img->bpp / 8] = text->data[tex_y * text->size_line + tex_x  * text->bpp / 8];
  win->img->data[y * win->img->size_line + x * win->img->bpp / 8 + 1] = text->data[tex_y * text->size_line + tex_x  * text->bpp / 8 + 1];
  win->img->data[y * win->img->size_line + x * win->img->bpp / 8 + 2] = text->data[tex_y * text->size_line + tex_x  * text->bpp / 8 + 2];
}

void vert_tex(int y0, int y1)
{
  int y;
  int y_max;

  if (y0 < y1)
  {
    y = y0;
    y_max = y1;
  }
  else
  {
    y = y1;
    y_max = y0;
  }
  if (y >= 0)
  {
    while (y < y_max)
    {
      texture_on_img(ray->pix, y);
      y++;
    }
  }
}
