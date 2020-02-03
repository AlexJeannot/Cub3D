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
  printf("AVANT CHECK ARG\n");
  check_arg(path);
  printf("APRES CHECK ARG\n");
  fd = check_open_config(path);
  printf("APRES CHECK OPEN CONFIG\n");
  while ((ret = get_next_line(fd, &str)) > 0)
  {
    if (ret == -1)
      exit_game("Erreur lors du parcours du fichier de configuration\n");
    printf("STR = %s\n", str);
    if (str[0] != '\0')
    {
      printf("ENTRE IF \n");
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
      printf("FIN PARSE\n");
    }
    else
      if (config->map == 1 && ret != 0)
        exit_game("description de la map avec un \\n\n");
    //free(str);
  }
  printf("APRES GNL\n");
  map_into_array();
  printf("APRES MAP INTO ARRAY\n");
  check_map_error();
  printf("APRES CHECK MAP ERROR\n");
  free(config);
  return (OK);
}

void parse_resolution(char *str)
{
  int cmp;

//  printf("ENTREE PARSE RESO\n");
  cmp = 1;
//  printf("STR = %s\n", str);
  while (str[cmp] == ' ')
    cmp++;
  if (str[cmp] >= '0' && str[cmp] <= '9')
  {
    win->width = ft_atoi_cub(&str[cmp]);
  //  printf("win->width = %d\n", win->width);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] < '0' || str[cmp] > '9')
      exit_game("Caractère invalide entre la largeur et la hauteur de la résolution\nExemple de format attendu : R 1920 1080\n");
    win->height = ft_atoi_cub(&str[cmp]);
  //  printf("win->height = %d\n", win->height);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
  //  printf("POST NB\n");
    while (str[cmp] == ' ')
      cmp++;
  //  printf("POST SPACE\n");
  //  printf("STR[%d] = %d\n", cmp, str[cmp]);
    if (str[cmp] != '\0')
      exit_game("Caractère invalide après la définition de la résolution\nExemple de format attendu : R 1920 1080\n");
    config->resolution = 1;
    printf("POST BACKN\n");
  }
  else
    exit_game("Caractère invalide avant definition de la largeur\nExemple de format attendu : R 1920 1080\n");
}

void parse_texture(char *str, int index)
{
  int cmp;
  int cmp_2;
  int len;
  char *path;

  cmp = 2;
  len = ft_strlen(str);
//  printf("str = %s\nstr[len - 4] = %c\nindex = %d\n", str, str[len - 4], index);
  if (str[len - 4] != '.' && str[len - 3] != 'x' && str[len - 2] != 'p' && str[len - 1] != 'm')
    exit_game("Extension du fichier de texture invalide\nExtension attendue : .xpm");
  while (str[cmp] == ' ')
    cmp++;
  cmp_2 = 0;
  if (str[cmp] == '.')
  {
//    printf("ENTREE IF TEXTURE\n");
    path = (char *)malloc(sizeof(char) * (len - cmp + 1));
    while (str[cmp] >= ' ' && str[cmp] <= '~')
    {
      path[cmp_2] = str[cmp];
      cmp_2++;
      cmp++;
    }
    path[cmp_2] = '\0';
  //  printf("path = %s\n", path);
    if (open(path, O_RDONLY) == -1)
    {
  //    printf("OPEN KO TEXTURE\n");
      exit_game("Fichier de texture introuvable\n");
    }
    else
      init_texture(path, index);
  }
  else
    exit_game("caractere entre indice et path\n");
}

int create_rgb(int color_value, int rgb, char color, char type)
{

  printf("color_value = %d\n", color_value);
  if (check_error_rgb_value(color_value, color, type) != -1)
  {
    printf("ENTRE TRAITEMENT COLOR\n");
    if (color == 'r')
      rgb = color_value;
    else if (color == 'g')
      rgb = (rgb << 8) + color_value;
    else if (color == 'b')
    {
      rgb = (rgb << 8) + color_value;
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
      {
        win->floor_color = create_rgb(ft_atoi_cub(&str[cmp]), win->floor_color, color, str[0]);
        printf("floor_color = %d\n", win->floor_color);
      }
      else if (str[0] == 'C')
      {
        win->ceiling_color = create_rgb(ft_atoi_cub(&str[cmp]), win->floor_color, color, str[0]);
        printf("ceiling_color = %d\n", win->ceiling_color);
      }
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
  if (str[0] == 'F')
    config->rgb_f = 1;
  if (str[0] == 'C')
    config->rgb_c = 1;
//  printf("str[cmp] = %c\n", str[cmp]);
  if (str[cmp] != '\0')
    exit_game("caractere invalide post rgb\n");
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


void parse_map(char *str)
{
  int len;

  len = ft_strlen(str);
//  printf("str[len - 1] = %c\n", str[len - 1]);
/*  if (str[len - 1] != '1')
    exit_game("dernier caractere de la ligne n'est pas un 1\n");*/
//  printf("ft_strlen(win->my_map->map_str) = %d\nft_strlen(str) = %d\n", ft_strlen(win->my_map->map_str), ft_strlen(str));
  if (config->map == 0)
  {
    check_all_config_elem_before_map();
    win->my_map->map_str = ft_strjoin_cub(win->my_map->map_str, str, ft_strlen(win->my_map->map_str), ft_strlen(str));
/*    map[len] = '\n';
    map[len + 1] = '\0';*/
    win->my_map->width = ft_strlen_without_space(str);
    config->map = 1;
  }
  else
  {
  //  printf("ENTRE JOIN \n");
  //  printf("STR = %s\n", str);
    win->my_map->map_str = ft_strjoin_cub(win->my_map->map_str, str, ft_strlen(win->my_map->map_str), ft_strlen(str));
  }
//  printf("---- FIN JOIN MAP----\nwin->my_map->map_str = %s", win->my_map->map_str);
  win->my_map->height++;
}

void map_into_array(void)
{
  int cmp_array;
  int cmp_str;
  int cmp_global;
  char **map_array;
  char *map_str;
//  printf("AVANT PRINT MAP\n");
//  printf("\nwin->my_map->map_str = \n%s", win->my_map->map_str);
//  printf("win->my_map->height = %d\n", win->my_map->height);
//  printf("win->my_map->width = %d\n", win->my_map->width);
  cmp_array = 0;
  cmp_global = 0;
  map_array = malloc(sizeof(char *) * win->my_map->height);
  while (cmp_array < win->my_map->height)
  {
    cmp_str = 0;
    map_str = malloc(sizeof(char) * (win->my_map->width + 1));
    while (cmp_str < win->my_map->width)
    {
      while (win->my_map->map_str[cmp_global] == ' ' || win->my_map->map_str[cmp_global] == '\n')
        cmp_global++;
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
//  printf("%s\n", map_array[0]);
//  printf("%s\n", map_array[1]);
//  printf("%s\n", map_array[2]);
//  printf("%s\n", map_array[3]);
//  printf("%s\n", map_array[4]);
//  printf("%s\n", map_array[5]);
//  printf("%s\n", map_array[6]);
//  printf("%s\n", map_array[7]);
//  printf("%s\n", map_array[8]);
//  printf("%s\n", map_array[9]);
//  printf("%s\n", map_array[10]);
//  printf("%s\n", map_array[11]);
//  printf("%s\n", map_array[12]);
//  printf("%s\n", map_array[13]);
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
  config->player_position = 1;
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
