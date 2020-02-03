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

  if ((fd = open(path, O_RDONLY)) == -1)
  {
      exit_game("Erreur lors de la tentative d'ouverture du fichier\n");
      return (KO);
  }
  else
    return (fd);
}

void check_all_config_elem_before_map(void)
{
  if (config->resolution == 0)
    exit_game("pas de resolution avant map\n");
  else if (config->texture_no == 0)
    exit_game("pas de texture nord avant map\n");
  else if (config->texture_so == 0)
    exit_game("pas de texture sud avant map\n");
  else if (config->texture_ea == 0)
    exit_game("pas de texture est avant map\n");
  else if (config->texture_we == 0)
    exit_game("pas de texture ouest avant map\n");
  else if (config->rgb_f == 0)
    exit_game("pas de couleur floor avant map\n");
  else if (config->rgb_c == 0)
    exit_game("pas de couleur ceiling avant map\n");
  else if (config->sprite == 0)
    exit_game("pas de sprite avant map\n");
}
