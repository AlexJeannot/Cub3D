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

int check_error_rgb_value(int color_value, char color, char type)
{
  if (color_value > 255)
  {
    if (color == 'r' && type == 'F')
      exit_game("value of r and f\n");
    else if (color == 'r' && type == 'C')
      exit_game("value of r and f\n");
    else if (color == 'g' && type == 'F')
      exit_game("value of g and f\n");
    else if (color == 'g' && type == 'C')
      exit_game("value of g and f\n");
    else if (color == 'b' && type == 'F')
      exit_game("value of b and f\n");
    else if (color == 'b' && type == 'C')
      exit_game("value of b and f\n");
    return (KO);
  }
  return (OK);
}

int check_coma_between_rgb(char c, char color, char type)
{
  if (c == ',')
    return (OK);
  else
  {
    if (color == 'r' && type == 'F')
      exit_game("coma between r and b for floor\n");
    else if (color == 'r' && type == 'C')
      exit_game("coma between r and b for ceiling\n");
    else if (color == 'g' && type == 'F')
      exit_game("coma between g and b for floor\n");
    else if (color == 'g' && type == 'C')
      exit_game("coma between g and b for ceiling\n");
    return (KO);
  }
}

void error_before_rgb_value(int color, char type)
{
  if (color == 'r' && type == 'F')
    exit_game("caractere invalide avant r value for floor\n");
  else if (color == 'r' && type == 'C')
    exit_game("caractere invalide avant r value for ceiling\n");
  if (color == 'g' && type == 'F')
    exit_game("caractere invalide avant g value for floor\n");
  else if (color == 'g' && type == 'C')
    exit_game("caractere invalide avant g value for ceiling\n");
  if (color == 'b' && type == 'F')
    exit_game("caractere invalide avant b value for floor\n");
  else if (color == 'b' && type == 'C')
    exit_game("caractere invalide avant b value for ceiling\n");
}

void check_map_error(void)
{
  int cmp_array;
  int cmp_str;

  check_top_and_bottom_map(0);
  check_top_and_bottom_map(win->my_map->height - 1);
  cmp_array = 1;
  while (cmp_array < win->my_map->height - 1)
  {
  //  printf("ENTREE WHILE CHECK MAP\n");
    cmp_str = 0;
    if (win->my_map->map[cmp_array][0] != '1')
      exit_game("frontiere ouest non ferme\n");
    if (win->my_map->map[cmp_array][win->my_map->width - 1] != '1')
      exit_game("frontiere est non ferme\n");
    while (win->my_map->map[cmp_array][cmp_str])
    {
//      printf("ENTREE WHILE CHECK MAP PER ARRAY\n");
      while (win->my_map->map[cmp_array][cmp_str] == ' ')
        cmp_str++;
      if (win->my_map->map[cmp_array][cmp_str] == 'N' || win->my_map->map[cmp_array][cmp_str] == 'S' || win->my_map->map[cmp_array][cmp_str] == 'E' || win->my_map->map[cmp_array][cmp_str] == 'W')
        cmp_str += set_player_position(cmp_str, cmp_array, win->my_map->map[cmp_array][cmp_str]);
      else if (win->my_map->map[cmp_array][cmp_str] != '0' && win->my_map->map[cmp_array][cmp_str] != '1' && win->my_map->map[cmp_array][cmp_str] != '2')
        exit_game("chiffre invalide dans corps de la map\n");
      cmp_str++;
    }
    cmp_array++;
  //  printf("cmp_array = %d\n", cmp_array);
  }
  if (config->player_position == 0)
    exit_game("pas de position\n");
}

void check_top_and_bottom_map(int limit)
{
  int cmp_str;

  cmp_str = 0;

  while (win->my_map->map[limit][cmp_str])
  {
    while (win->my_map->map[limit][cmp_str] == ' ')
      cmp_str++;
    if (win->my_map->map[limit][cmp_str] != '1')
    {
      if (limit == 0)
        exit_game("frontiere nord non ferme\n");
      else if (limit == win->my_map->height - 1)
        exit_game("frontiere sud non ferme\n");
    }
    cmp_str++;
  }
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
