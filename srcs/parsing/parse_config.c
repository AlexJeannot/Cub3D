#include "../../includes/cub3D.h"

void init_config(void)
{
  if (!(config = malloc(sizeof(t_config))))
    exit_game("Error\nMemory allocation error\n");
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

/* Parsing de la ligne recupérée lors du gnl */
/* Si indice correspondant a un element alors parsing de la ligne autrement erreur */
void parse_line(char *str)
{
  int index_texture;

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
    exit_game("Error\nInvalid line in configuration file\n");
}

int parse_config(char *path)
{
  int ret;
  int fd;
  char *str;

  init_config(); // Initialisation de la structure config permettant de savoir si les differents elements sont présents
  arg_extension(path); // Verification si le fichier est bien un .cub
  fd = open_config(path);
  while ((ret = get_next_line(fd, &str)) > 0)
  {
    if (ret == -1)
      exit_game("Error\nWhile browsing configuration file\n");
    if (str[0] != '\0') // S'il ne s'agit pas d'un retour a la ligne alors parsing de la ligne
    {
      parse_line(str);
      free(str);
    }
    else
      if (config->map == 1 && ret != 0) // S'il s'agit d'un retour a la ligne lors de la description de la map alors erreur et exit
        exit_game("Error\nLine beak in map description\n");
  }
  free(str);
  map_into_array(); // Transformation de la map en tableau de strings
  check_map_error(); // Check des potentielles erreurs sur la map
  free(config);
  config = NULL;
  return (OK);
}
