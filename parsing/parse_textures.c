#include "../includes/cub3D.h"

int is_texture(char *str)
{
  int index;

  if (str[0] == 'N' && str[1] == 'O')
    index = 0;
  else if (str[0] == 'S' && str[1] == 'O')
    index = 1;
  else if (str[0] == 'W' && str[1] == 'E')
    index = 2;
  else if (str[0] == 'E' && str[1] == 'A')
    index = 3;
  else
    return (KO);
  if (index == 0 && config->texture_no == 1)
    exit_game("Error\nNorth texture already defined\n");
  else if (index == 1 && config->texture_so == 1)
    exit_game("Error\nSouth texture already defined\n");
  else if (index == 3 && config->texture_ea == 1)
    exit_game("Error\nEast texture already defined\n");
  else if (index == 2 && config->texture_we == 1)
    exit_game("Error\nWest texture already defined\n");

  return (index);
}

void texture_extension(char *str)
{
  int len;

  len = ft_strlen(str);
  if (str[len - 4] != '.' && str[len - 3] != 'x' && str[len - 2] != 'p' && str[len - 1] != 'm')
    exit_game("Error\nInvalid wall texture file extension\nExpected etension : .xpm\n");
}

void open_texture_file(char *path, int index)
{
  if (open(path, O_RDONLY) == -1)
    exit_game("Error\nWall texture file can't be open\n");
  else
    init_texture(path, index);
}

void parse_texture(char *str, int index)
{
  int cmp_str;
  int cmp_path;
  char *path;

  cmp_str = 2;
  cmp_path = 0;
  texture_extension(str);
  cmp_str += browse_space(&str[cmp_str]);
  if (str[cmp_str] == '.')
  {
    if (!(path = (char *)malloc(sizeof(char) * (ft_strlen(str) - cmp_str + 1))))
      exit_game("Error\nMemory allocation error\n");
    while (str[cmp_str] >= ' ' && str[cmp_str] <= '~')
    {
      path[cmp_path] = str[cmp_str];
      cmp_path++;
      cmp_str++;
    }
    path[cmp_path] = '\0';
    open_texture_file(path, index);
  }
  else
    exit_game("Error\nInvalid caracter before wall texture file path\n");
}
