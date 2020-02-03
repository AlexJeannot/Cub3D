#include "../includes/second_cube.h"

int is_texture(char *str)
{
  int index;

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

void parse_texture(char *str, int index)
{
  int cmp;
  int cmp_2;
  int len;
  char *path;

  cmp = 2;
  len = ft_strlen(str);
  if (str[len - 4] != '.' && str[len - 3] != 'x' && str[len - 2] != 'p' && str[len - 1] != 'm')
    exit_game("Extension du fichier de texture invalide\nExtension attendue : .xpm");
  while (str[cmp] == ' ')
    cmp++;
  cmp_2 = 0;
  if (str[cmp] == '.')
  {
    path = (char *)malloc(sizeof(char) * (len - cmp + 1));
    while (str[cmp] >= ' ' && str[cmp] <= '~')
    {
      path[cmp_2] = str[cmp];
      cmp_2++;
      cmp++;
    }
    path[cmp_2] = '\0';
    if (open(path, O_RDONLY) == -1)
    {
      exit_game("Fichier de texture introuvable\n");
    }
    else
      init_texture(path, index);
  }
  else
    exit_game("caractere entre indice et path\n");
}
