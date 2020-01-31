#include "../includes/second_cube.h"

void init_config(void)
{
  config = malloc(sizeof(t_config));
  config->resolution = 0;
  config->texture_no = 0;
  config->texture_so = 0;
  config->texture_we = 0;
  config->texture_ea = 0;
  config->rgb_f = 0;
  config->rgb_c = 0;
  config->map = 0;
}

int parse_config(char *path)
{
  int ret;
  int fd;
  char **str;
  int index_texture;

  init_config();
  check_arg(path);
  fd = check_open_config(path)
  while ((ret = get_next_line(fd, str)) >= 0)
  {
    if (ret == -1)
      exit_game("Erreur lors du parcours du fichier de configuration\n");
    else if (is_resolution(str))
      parse_resolution(str);
    else if ((index_texture = is_texture(str)) != -1 && is_texture_already_init(index_texture) == 1)
      parse_texture(str, index_texture);
    else if (is_rgb(str))
      parse_rgb(str);
    else if (is_map(str))
      parse_map(str);
  }
}

void parse_resolution(char *str)
{
  int cmp;

  cmp = 1;
  while (str[cmp] == ' ')
    cmp++;
  if (str[cmp] >= '0' && str[cmp] =< '9')
  {
    win->width = ft_atoi(&str[cmp]);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] < '0' || str[cmp] > '9')
      exit_game("Caractère invalide entre la largeur et la hauteur de la résolution\nExemple de format attendu : R 1920 1080\n");
    win->height = ft_atoi(&str[cmp]);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
    if (str[cmp] != '\n')
      exit_game("Caractère invalide après la définition de la résolution\nExemple de format attendu : R 1920 1080\n");
    config->resolution = 1;
  }
  exit_game("Caractère invalide avant definition de la largeur\nExemple de format attendu : R 1920 1080\n");
}

void parse_texture(char *str, index)
{
  int cmp;
  int len;
  char *path;

  cmp = 2;
  len = ft_strlen(str);
  if (str[len - 5] != '.' && str[len - 4] != 'x' && str[len - 3] != 'p' && str[len - 2] != 'm')
    exit_game("Extension du fichier de texture invalide\nExtension attendue : .xpm");
  while (str[cmp] == ' ')
    cmp++;
  len = 0;
  if (str[cmp] == '.')
  {
    path = (char *)malloc(sizeof(char) * (len - cmp))
    while (str[cmp] >= ' ' && str[cmp] <= '~')
    {
      path[len] = str[cmp];
      len++;
      cmp++;
    }
    path[len] = '\0';
    if (open(path, O_RDONLY) == -1)
      exit_game("Fichier de texture introuvable\n");
    else
      init_texture(path, index);
  }
  exit_game("caractere entre indice et path\n");
}

void parse_rgb(char *str)
{
  int cmp;

  cmp = 1;
  while (str[cmp] == ' ')
    cmp++;
  if (str[cmp] >= '0' && str[cmp] =< '9')
  {

  }
  exit_game("caractere entre incide ce r\n");
}
