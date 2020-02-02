#include "../includes/second_cube.h"

void set_sprite(char *path)
{
  t_image *new_sprite;

  new_sprite = malloc(sizeof(t_image));

  new_sprite->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, path, &new_sprite->width, &new_sprite->height);
  new_sprite->data = mlx_get_data_addr(new_sprite->img_ptr, &new_sprite->bpp, &new_sprite->size_line, &new_sprite->endian);

  win->sprite = new_sprite;
}

void add_displayable_sprite(void)
{
  t_sprites *new_sprite;
  t_sprites *browse;

  new_sprite = malloc(sizeof(t_sprites));
  new_sprite->x = ray->mapx;
  new_sprite->y = ray->mapy;
  new_sprite->next = NULL;
  if (win->have_sprite == 0)
  {
    win->displayable_sprite = new_sprite;
    win->have_sprite += 1;
  }
  else
  {
    browse = win->displayable_sprite;
    while (browse->next && (browse->x != new_sprite->x || browse->y != new_sprite->y))
    {
      browse = browse->next;
    }
    if (browse->x != new_sprite->x || browse->y != new_sprite->y)
    {
      browse->next = new_sprite;
      win->have_sprite += 1;
    }
    else
      free(new_sprite);
  }
}

void sort_displayable_sprites(void)
{
  t_sprite_list *tmp;
  t_sprite_list **sprite_list;
  int distance_first;
  int distance_second;
  int cmp;

  cmp = 0;
  sprite_list = sp->sprite_list;
  while(sprite_list[cmp + 1]->x != -1)
  {
    distance_first = ((win->player->pos_x - sprite_list[cmp]->x) * (win->player->pos_x - sprite_list[cmp]->x) + (win->player->pos_y - sprite_list[cmp]->y) * (win->player->pos_y - sprite_list[cmp]->y));
    distance_second = ((win->player->pos_x - sprite_list[cmp + 1]->x) * (win->player->pos_x - sprite_list[cmp + 1]->x) + (win->player->pos_y - sprite_list[cmp + 1]->y) * (win->player->pos_y - sprite_list[cmp + 1]->y));
    if (distance_first < distance_second)
    {
      tmp = sprite_list[cmp];
      sprite_list[cmp] = sprite_list[cmp + 1];
      sprite_list[cmp + 1] = tmp;
      cmp = 0;
    }
    else
      cmp++;
  }
}

void delete_diplayed_sprites(void)
{
  t_sprites *to_delete;
  int cmp;

  cmp = 0;
  if (win->have_sprite != 0)
  {
    while (cmp <= win->have_sprite)
    {
      free(sp->sprite_list[cmp]);
      cmp++;
    }
    free(sp->sprite_list);
    win->have_sprite = 0;
    while (win->displayable_sprite)
    {
      to_delete = win->displayable_sprite;
      win->displayable_sprite = win->displayable_sprite->next;
      to_delete->x = -1;
      to_delete->y = -1;
      to_delete->next = NULL;
      free(to_delete);
    }
    free(sp);
  }
}

void into_list(void)
{
  t_sprites *browse;
  t_sprite_list *new_sprite;
  t_sprite_list *last_sprite;
  int cmp;

  cmp = 0;
  browse = win->displayable_sprite;
  last_sprite = malloc(sizeof(t_sprite_list));
  browse = win->displayable_sprite;
  if (browse)
  {
    while (browse)
    {
      new_sprite = malloc(sizeof(t_sprite_list));
      new_sprite->x = browse->x;
      new_sprite->y = browse->y;
      sp->sprite_list[cmp] = new_sprite;
      browse = browse->next;
      cmp++;
    }
  }
  last_sprite->y = -1;
  last_sprite->x = -1;
  sp->sprite_list[cmp] = last_sprite;
}
