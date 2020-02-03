#include "../includes/second_cube.h"

int is_resolution(char *str)
{
//  printf("ENTREE IS RESO\n");
//  printf("STR[0] = %c\n", str[0]);
  if (str[0] == 'R')
  {
    if (config->resolution == 1)
      exit_game("Resolution deja defini\n");
//    printf("ENTREE OKK RESO\n");
    return (OK);
  }
  return (KO);
}

int is_texture(char *str)
{
  int index;

//  printf("ENTREE IS TEXTURE\n");
  if (str[0] == 'N' && str[1] == 'O')
    index = 0;
  else if (str[0] == 'S' && str[1] == 'O')
    index = 1;
  else if (str[0] == 'W' && str[1] == 'E')
    index = 2;
  else if (str[0] == 'E' && str[1] == 'A')
    index = 3;
  else
    return (KO);
  if (index == 0 && config->texture_no == 1)
    exit_game("Texture NORD déjà définie\n");
  else if (index == 1 && config->texture_so == 1)
    exit_game("Texture SUD déjà définie\n");
  else if (index == 2 && config->texture_we == 1)
    exit_game("Texture OUEST déjà définie\n");
  else if (index == 3 && config->texture_ea == 1)
    exit_game("Texture EST déjà définie\n");
  return (index);
}

int is_rgb(char *str)
{
  if (str[0] == 'F' || str[0] == 'C')
  {
    if (str[0] == 'F' && config->rgb_f == 1)
      exit_game("rgb floor already set\n");
    else if (str[0] == 'C' && config->rgb_c == 1)
      exit_game("rgb ceiling already set\n");
    return (OK);
  }
  return (KO);
}

int is_sprite(char *str)
{
  if (str[0] == 'S')
  {
    if (config->sprite == 1)
      exit_game("sprite already set\n");
    return (OK);
  }
  return (KO);
}

int is_map(char *str)
{
  int cmp;

  cmp = 0;
  while (str[cmp] == ' ')
    cmp++;
  if (config->map == 1)
  {
    if (str[cmp] == '1')
      return (OK);
    else
      exit_game("ligne de map non conforme");
    return (KO);
  }
  else
  {
    if (str[cmp] == '1')
      return (OK);
    else
      return (KO);
  }
}
