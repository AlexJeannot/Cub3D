#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minilibx/mlx.h"

int main(void)
{
  void *ptr_mlx;
  void *ptr_window;
  int x;
  int y;


  ptr_mlx = mlx_init();
  ptr_window = mlx_new_window(ptr_mlx, 1000, 1000, "test");

  y = 0;
  while (y < 1000)
	{
		x = 0;
    if (y < 500)
    {
  		while (x < 1000)
  		{
        if (x < 500)
  			     mlx_pixel_put(ptr_mlx, ptr_window, x, y, 0x336BFF);
        else
            mlx_pixel_put(ptr_mlx, ptr_window, x, y, 0xd4008b);
  			x++;
  		}
    }
    else
    {
      while (x < 1000)
  		{
        if (x < 500)
             mlx_pixel_put(ptr_mlx, ptr_window, x, y, 0x80FFE0);
        else
            mlx_pixel_put(ptr_mlx, ptr_window, x, y, 0x990000);
  			x++;
  		}
    }
		y++;
	}

  mlx_loop(ptr_mlx);
  mlx_destroy_window(ptr_mlx, ptr_window);
  //system("killall afplay");
  //exit(0);
  return (0);
}
