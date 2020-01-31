#include "../includes/second_cube.h"

int parse_config(char *path)
{
  int ret;
  int fd;
  char **str;

  check_arg(path);
  fd = check_open_config(path)
  while ((ret = get_next_line(fd, str)) >= 0)
  {
    if (ret == -1)
      exit_game("Erreur lors du parcours du fichier de configuration\n");
    else if (is_resolution(str))
      parse_resolution(str);
    else if (is_texture(str))
      parse_texture(str);
    else if (is_rgb(str))
      parse_rgb(str);
    else if (is_map(str))
      parse_map(str);
  }
}

void parse_resolution(char *str)
{
  int cmp;

  cmp = 0;
  while (str[cmp] < '0' || str[cmp] > '9')
    cmp++;
  win->width = ft_atoi(&str[cmp]);
  while (str[cmp] >= '0' && str[cmp] <= '9')
    cmp++;
  while (str[cmp] == ' ')
    cmp++;
  if (str[cmp] < '0' || str[cmp] > '9')
    exit_game("Caractère invalide entre la largeur et la hauteur de la résolution\nFormat attendu : R 1920 1080\n");
  else
    win->height = ft_atoi(&str[cmp]);
  while (str[cmp] >= '0' && str[cmp] <= '9')
    cmp++;
  if (str[cmp] != '\n')
    exit_game("Caractère invalide après la définition de la résolution\nFormat attendu : R 1920 1080\n");
}

void parse_texture(char *str)
{
  int cmp;
  int len;

  cmp = 0;
  len = ft_strlen(str);
  if (str[len - 5] != '.' && str[len - 4] != 'x' && str[len - 3] != 'p' && str[len - 2] != 'm')
    exit_game("Extension du fichier de texture invalide\nFormat attendu : .xpm");
  while (str[cmp] != '.')
    cmp++;
  while (str[cmp] >= ' ' && str[cmp] <= '~')





  win->width = ft_atoi(&str[cmp]);
  while (str[cmp] >= '0' && str[cmp] <= '9')
    cmp++;
  while (str[cmp] == ' ')
    cmp++;
  if (str[cmp] < '0' || str[cmp] > '9')
    exit_game("Caractère invalide entre la largeur et la hauteur de la résolution\nFormat attendu : R 1920 1080\n");
  else
    win->height = ft_atoi(&str[cmp]);
  while (str[cmp] >= '0' && str[cmp] <= '9')
    cmp++;
  if (str[cmp] != '\n')
    exit_game("Caractère invalide après la définition de la résolution\nFormat attendu : R 1920 1080\n");
}
