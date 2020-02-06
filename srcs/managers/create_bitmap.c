#include "../../includes/cub3D.h"


void set_bitmap_header(int fd, int bmp_size, int totalheader_size)
{
  write(fd, "BM", 2);
  write(fd, &bmp_size, 4);
  write(fd, "\0\0\0\0", 4);
  write(fd, &totalheader_size, 4);
}

void set_bitmap_infoheader(int fd, int infoheader_size)
{
  int planes;
  int cmp;

  cmp = 0;
  planes = 1;
  write(fd, &infoheader_size, 4);
  write(fd, &win->width, 4);
  write(fd, &win->height, 4);
  write(fd, &planes, 2);
  write(fd, &img->bpp, 2);
  while (cmp < 28)
  {
    write(fd, "\0", 1);
    cmp++;
  }
}

void set_data_bitmap(int fd)
{
  int cmp;
  int cmp_w;

  cmp = win->width * win->height + 1;
  while (cmp >= 0)
  {
    cmp_w = 0;
    cmp = cmp - win->width;
    while (cmp_w < win->width)
    {
      write(fd, &img->data[cmp * img->bpp / 8], 4);
      cmp_w++;
      cmp++;
    }
    cmp = cmp - win->width;
  }
}

void create_bitmap(void)
{
  int fd;
  int bmp_size;
  int header_size;
  int infoheader_size;
  int totalheader_size;

  fd = open("save.bmp", O_CREAT | O_WRONLY  | O_TRUNC, S_IRWXU);
  header_size = 14;
  infoheader_size = 40;
  totalheader_size = header_size + infoheader_size;
  bmp_size = totalheader_size + (win->width * win->height * 4);
  set_bitmap_header(fd, bmp_size, totalheader_size);
  set_bitmap_infoheader(fd, infoheader_size);
  set_data_bitmap(fd);
  close(fd);
  exit_game(NULL);
}
