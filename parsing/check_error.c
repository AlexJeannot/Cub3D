#include "../includes/second_cube.h"

int check_arg(char *str)
{
  int cmp;

  cmp = ft_strlen(str);
  if (str[cmp - 4] != '.' && str[cmp - 3] != 'b' && str[cmp - 2] != 'u' && str[cmp - 1] != 'c')
  {
    exit_game("Extension du fichier de configuration invalide\nFormat attendu : .cub");
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
