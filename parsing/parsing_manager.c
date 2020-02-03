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
  while ((ret = get_next_line(fd, &str)) > 0)
  {
    if (ret == -1)
      exit_game("Erreur lors du parcours du fichier de configuration\n");
    if (str[0] != '\0')
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
      if (config->map == 1 && ret != 0)
        exit_game("description de la map avec un \\n\n");
  }
  map_into_array();
  check_map_error();
  free(config);
  return (OK);
}
