#include "../includes/cub3D.h"

void	display_pixel_texture(int x, int y)
{
	int d;
	int tex_x;
  int tex_y;
  t_image *text;

  if (ray->side == 0)
    text = textures[3];
  else if (ray->side == 1)
    text = textures[2];
  else if (ray->side == 2)
    text = textures[1];
  else
    text = textures[0];

  tex_x = (int)(ray->wall_x * (double)text->width);

  d = y * text->size_line - (win->height * player->cam_height) * text->size_line / 2 + ray->wall_height * text->size_line / 2;
  tex_y = ((d * text->height) / ray->wall_height) / text->size_line;

  img->data[y * img->size_line + x * img->bpp / 8] = text->data[tex_y * text->size_line + tex_x  * text->bpp / 8];
  img->data[y * img->size_line + x * img->bpp / 8 + 1] = text->data[tex_y * text->size_line + tex_x  * text->bpp / 8 + 1];
  img->data[y * img->size_line + x * img->bpp / 8 + 2] = text->data[tex_y * text->size_line + tex_x  * text->bpp / 8 + 2];
}

void display_vertical_texture(int y_start, int y_end)
{
  if (y_start >= 0)
    while (y_start < y_end)
    {
      display_pixel_texture(ray->line_x, y_start);
      y_start++;
    }
}
