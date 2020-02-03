#include "../includes/second_cube.h"

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

void parse_sprite(char *str)
{
  int cmp;
  int cmp_2;
  int len;
  char *path;

  cmp = 1;
  len = ft_strlen(str);
  if (str[len - 4] != '.' && str[len - 3] != 'x' && str[len - 2] != 'p' && str[len - 1] != 'm')
    exit_game("Extension du fichier de sprite invalide\nExtension attendue : .xpm");
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
      exit_game("Fichier de sprite introuvable\n");
    else
      set_sprite(path);
  }
  else
    exit_game("caractere entre indice et path\n");
  config->sprite = 1;
}
