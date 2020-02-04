#include "../includes/cub3D.h"

void init_sprite(char *path)
{
  if (!(s_texture = malloc(sizeof(t_image))))
    exit_game("Error\nMemory allocation error\n");
  s_texture->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, path, &s_texture->width, &s_texture->height);
  s_texture->data = mlx_get_data_addr(s_texture->img_ptr, &s_texture->bpp, &s_texture->size_line, &s_texture->endian);
  free(path);
}

t_displayable_sprites *init_displayable_sprite(void)
{
  t_displayable_sprites *new_elem;

  if (!(new_elem = malloc(sizeof(t_displayable_sprites))))
    exit_game("Error\nMemory allocation error\n");
  new_elem->x = ray->map_x;
  new_elem->y = ray->map_y;
  new_elem->next = NULL;
  return (new_elem);
}

void add_displayable_sprite(void)
{
  t_displayable_sprites *browse;

  if (win->have_sprite == 0)
  {
    s_displayable = init_displayable_sprite();
    win->have_sprite += 1;
  }
  else
  {
    browse = s_displayable;
    while (browse->next && (browse->x != ray->map_x || browse->y != ray->map_y))
      browse = browse->next;
    if (browse->x != ray->map_x || browse->y != ray->map_y)
    {
      browse->next = init_displayable_sprite();
      win->have_sprite += 1;
    }
  }
}

void sort_displayable_sprites(void)
{
  t_sprite_array *tmp;
  t_sprite_array **sprite_list;
  int distance_first;
  int distance_second;
  int cmp;

  cmp = 0;
  sprite_list = s_array;
  while(sprite_list[cmp + 1]->x != -1)
  {
    distance_first = ((player->pos_x - sprite_list[cmp]->x) * (player->pos_x - sprite_list[cmp]->x) + (player->pos_y - sprite_list[cmp]->y) * (player->pos_y - sprite_list[cmp]->y));
    distance_second = ((player->pos_x - sprite_list[cmp + 1]->x) * (player->pos_x - sprite_list[cmp + 1]->x) + (player->pos_y - sprite_list[cmp + 1]->y) * (player->pos_y - sprite_list[cmp + 1]->y));
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

void free_diplayed_sprites(void)
{
  t_displayable_sprites *to_delete;
  int cmp;

  cmp = 0;
  if (win->have_sprite != 0)
  {
    while (cmp <= win->have_sprite)
    {
      if (s_array[cmp])
        free(s_array[cmp]);
        s_array[cmp] = NULL;
      cmp++;
    }
    free(s_array);
    s_array = NULL;
    win->have_sprite = 0;
    while (s_displayable)
    {
      to_delete = s_displayable;
      s_displayable = s_displayable->next;
      to_delete->next = NULL;
      free(to_delete);
      to_delete = NULL;
    }
    if (s_draw)
    {
      free(s_draw);
      s_draw = NULL;
    }
  }
}

void sprites_into_array(void)
{
  int cmp;
  t_displayable_sprites *browse;
  t_sprite_array *new_sprite;
  t_sprite_array *last_sprite;

  cmp = 0;
  browse = s_displayable;
  if (!(last_sprite = malloc(sizeof(t_sprite_array))))
    exit_game("Error\nMemory allocation error\n");
  browse = s_displayable;
  if (browse)
  {
    while (browse)
    {
      if (!(new_sprite = malloc(sizeof(t_sprite_array))))
        exit_game("Error\nMemory allocation error\n");
      new_sprite->x = browse->x;
      new_sprite->y = browse->y;
      s_array[cmp] = new_sprite;
      browse = browse->next;
      cmp++;
    }
  }
  last_sprite->y = -1;
  last_sprite->x = -1;
  s_array[cmp] = last_sprite;
}
