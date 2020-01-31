#include "../includes/second_cube.h"

void		pixel_put_to_image(int color, int x, int y)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];

	win->img->data[y * win->img->size_line + x * win->img->bpp / 8] = r;
	win->img->data[y * win->img->size_line + x * win->img->bpp / 8 + 1] = g;
	win->img->data[y * win->img->size_line + x * win->img->bpp / 8 + 2] = b;
}

void vert(int color, int y0, int y1)
{
  if (y0 >= 0)
  {
    while (y0 < y1)
    {
      pixel_put_to_image(color, ray->pix, y0);
      y0++;
    }
  }
}
