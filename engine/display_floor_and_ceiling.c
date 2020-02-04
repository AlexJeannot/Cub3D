#include "../includes/cub3D.h"

void		display_pixel_color(int color, int x, int y)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];

	img->data[y * img->size_line + x * img->bpp / 8] = r;
	img->data[y * img->size_line + x * img->bpp / 8 + 1] = g;
	img->data[y * img->size_line + x * img->bpp / 8 + 2] = b;
}

void display_vertical_color(int color, int y_start, int y_end)
{
  if (y_start >= 0)
    while (y_start < y_end)
    {
      display_pixel_color(color, ray->line_x, y_start);
      y_start++;
    }
}
