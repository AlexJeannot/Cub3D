#include "../includes/second_cube.h"

int check_arg(char *str)
{
  int cmp;

  cmp = ft_strlen(str);
  if (str[cmp - 4] != '.' && str[cmp - 3] != 'b' && str[cmp - 2] != 'u' && str[cmp - 1] != 'c')
  {
    exit_game("Extension du fichier de configuration invalide\nExtension attendue : .cub");
    return (KO);
  }
  else
    return (OK);
}

int check_open_config(char *path)
{
  int fd;

  if ((fd = open(path, RD_ONLY)) == -1)
  {
      exit_game("Erreur lors de la tentative d'ouverture du fichier\n");
      return (KO);
  }
  else
    return (fd);
}

int is_texture_already_init(int index)
{
  if (index == 0 && config->texture_no == 1)
    exit_game("Texture NORD déjà définie\n");
  else if (index == 1 && config->texture_so == 1)
    exit_game("Texture SUD déjà définie\n");
  else if (index == 2 && config->texture_we == 1)
    exit_game("Texture OUEST déjà définie\n");
  else if (index == 3 && config->texture_ea == 1)
    exit_game("Texture EST déjà définie\n");
  return (OK);
}
