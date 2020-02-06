#include "../../includes/cub3D.h"

/* modification des données dans img->data */
void		display_pixel_color(int color, int x, int y)
{
	int r;
	int g;
	int b;

	b = color % 256;
	color = (color - b) / 256;
	g = color % 256;
	color = (color - g) / 256;
	r = color;

	img->data[y * img->size_line + x * img->bpp / 8] = (char)r;
	img->data[y * img->size_line + x * img->bpp / 8 + 1] = (char)g;
	img->data[y * img->size_line + x * img->bpp / 8 + 2] = (char)b;
}

/* Parcours des pixel en hauteur */
void display_vertical_color(int color, int y_start, int y_end)
{
  while (y_start < y_end)
  {
    display_pixel_color(color, ray->line_x, y_start);
    y_start++;
  }
}
