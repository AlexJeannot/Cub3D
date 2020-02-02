#include "../includes/second_cube.h"

void init_config(void)
{
  config = malloc(sizeof(t_config));
  config->resolution = 0;
  config->texture_no = 0;
  config->texture_so = 0;
  config->texture_ea = 0;
  config->texture_we = 0;
  config->rgb_f = 0;
  config->rgb_c = 0;
  config->sprite = 0;
  config->map = 0;
  config->player_position = 0;
}

int parse_config(char *path)
{
  int ret;
  int fd;
  char *str;
  int index_texture;

  init_config();
  check_arg(path);
  fd = check_open_config(path);
  while ((ret = get_next_line(fd, str)) >= 0)
  {
    if (ret == -1)
      exit_game("Erreur lors du parcours du fichier de configuration\n");
    if (str[0] != '\n')
    {
      if (is_resolution(str) != -1)
        parse_resolution(str);
      else if ((index_texture = is_texture(str)) != -1)
        parse_texture(str, index_texture);
      else if (is_rgb(str) != -1)
        parse_rgb(str);
      else if (is_sprite(str) != -1)
        parse_sprite(str);
      else if (is_map(str) != -1)
        parse_map(str);
      else
        exit_game("Ligne non conforme\n");
    }
    else
      if (config->map == 1)
        exit_game("description de la map avec un \\n\n");
  }
  map_into_array();
  check_map_error();
  free(config);
  return (OK);
}

void parse_resolution(char *str)
{
  int cmp;

  cmp = 1;
  while (str[cmp] == ' ')
    cmp++;
  if (str[cmp] >= '0' && str[cmp] <= '9')
  {
    win->width = ft_atoi_cub(&str[cmp]);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] < '0' || str[cmp] > '9')
      exit_game("Caractère invalide entre la largeur et la hauteur de la résolution\nExemple de format attendu : R 1920 1080\n");
    win->height = ft_atoi_cub(&str[cmp]);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] != '\n')
      exit_game("Caractère invalide après la définition de la résolution\nExemple de format attendu : R 1920 1080\n");
    config->resolution = 1;
  }
  exit_game("Caractère invalide avant definition de la largeur\nExemple de format attendu : R 1920 1080\n");
}

void parse_texture(char *str, int index)
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
    path = (char *)malloc(sizeof(char) * (len - cmp));
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

int create_rgb(int color_value, char color, char type)
{
  static int rgb;

  if (check_error_rgb_value(color_value, color, type) != -1)
  {
    if (color == 'r')
      rgb = color;
    else if (color == 'g')
      rgb = (rgb << 8) + color;
    else if (color == 'b')
    {
      rgb = (rgb << 8) + color;
      rgb = 0;
    }
    return (rgb);
  }
  return (KO);
}

void parse_rgb(char *str)
{
  int cmp;
  int index;
  char color;

  cmp = 1;
  index = 0;
  while (str[cmp] == ' ')
    cmp++;
  while ((config->rgb_f != 1 && str[0] == 'F') || (config->rgb_c != 1 && str[0] == 'C'))
  {
    if (index == 0)
      color = 'r';
    else if (index == 1)
      color = 'g';
    else if (index == 2)
      color = 'b';
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] >= '0' && str[cmp] <= '9')
    {
      if (str[0] == 'F')
        win->floor_color = create_rgb(ft_atoi_cub(&str[cmp]), color, str[0]);
      else if (str[0] == 'C')
        win->ceiling_color = create_rgb(ft_atoi_cub(&str[cmp]), color, str[0]);
    }
    else
      error_before_rgb_value(color, str[0]);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
    while (str[cmp] == ' ')
      cmp++;
    if (index == 2)
      break ;
    cmp += check_coma_between_rgb(str[cmp], color, str[0]);
    index++;
  }
  if (str[cmp] != '\n')
    exit_game("caractere invalide post rgb\n");
}

void parse_sprite(char *str)
{
  int cmp;
  int len;
  char *path;

  cmp = 1;
  len = ft_strlen(str);
  if (str[len - 5] != '.' && str[len - 4] != 'x' && str[len - 3] != 'p' && str[len - 2] != 'm')
    exit_game("Extension du fichier de sprite invalide\nExtension attendue : .xpm");
  while (str[cmp] == ' ')
    cmp++;
  len = 0;
  if (str[cmp] == '.')
  {
    path = (char *)malloc(sizeof(char) * (len - cmp));
    while (str[cmp] >= ' ' && str[cmp] <= '~')
    {
      path[len] = str[cmp];
      len++;
      cmp++;
    }
    path[len] = '\0';
    if (open(path, O_RDONLY) == -1)
      exit_game("Fichier de sprite introuvable\n");
    else
      set_sprite(path);
  }
  exit_game("caractere entre indice et path\n");
}


void parse_map(char *str)
{
  int len;
  char *map;

  len = ft_strlen(str);
  if (str[len - 2] != 1)
    exit_game("dernier caractere de la ligne n'est pas un 1\n");
  if (config->map == 0)
  {
    check_all_config_elem_before_map();
    map = malloc(sizeof(char) * (len + 1));
    map = str;
    map[len] = '\0';
    win->my_map->width = len - 1;
    config->map = 1;
  }
  else
  {
    if (len - 1 != win->my_map->width)
      exit_game("longueur de la map non conforme");
    map = ft_strjoin_cub(map, str, ft_strlen(map), ft_strlen(str));
  }
  win->my_map->map_str = map;
  win->my_map->height++;
}

void map_into_array(void)
{
  int cmp_array;
  int cmp_str;
  int cmp_global;
  char **map_array;
  char *map_str;

  cmp_array = 0;
  cmp_global = 0;
  map_array = malloc(sizeof(char *) * win->my_map->height);

  while (cmp_array < win->my_map->height)
  {
    cmp_str = 0;
    map_str = malloc(sizeof(char) * (win->my_map->width + 1));
    while (cmp_str < win->my_map->width)
    {
      map_str[cmp_str] = win->my_map->map_str[cmp_global];
      cmp_str++;
      cmp_global++;
    }
    map_str[cmp_str] = '\0';
    map_array[cmp_array] = map_str;
    cmp_array++;
    cmp_global++;
  }
  win->my_map->map = map_array;
  free(win->my_map->map_str);
}

int set_player_position(int x, int y, char orientation)
{
  if (config->player_position == 1)
  {
    exit_game("Redefinition de player position\n");
    return (KO);
  }
  win->player->pos_x = x - 1;
  win->player->pos_y = y - 1;
  if (orientation == 'N' || orientation == 'S')
    set_player_dir_n_or_s(orientation);
  else if (orientation == 'E' || orientation == 'W')
    set_player_dir_e_or_w(orientation);
  win->my_map->map[y][x] = '0';
  return (OK);
}

void set_player_dir_n_or_s(char orientation)
{
  if (orientation == 'N')
  {
    win->player->dir_x = 0.0;
    win->player->dir_y = -1.0;
    win->player->plane_x = 0.66;
    win->player->plane_y = 0.0;
  }
  else if (orientation == 'S')
  {
    win->player->dir_x = 0.0;
    win->player->dir_y = 1.0;
    win->player->plane_x = -0.66;
    win->player->plane_y = 0.0;
  }
}

void set_player_dir_e_or_w(char orientation)
{
  if (orientation == 'E')
  {
    win->player->dir_x = 1.0;
    win->player->dir_y = 0.0;
    win->player->plane_x = 0.0;
    win->player->plane_y = 0.66;
  }
  else if (orientation == 'W')
  {
    win->player->dir_x = -1.0;
    win->player->dir_y = 0.0;
    win->player->plane_x = 0.0;
    win->player->plane_y = -0.66;
  }
}
