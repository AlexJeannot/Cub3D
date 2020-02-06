#include "../../includes/cub3D.h"

int is_rgb(char *str)
{
  if (str[0] == 'F' || str[0] == 'C')
  {
    if (str[0] == 'F' && config->rgb_f == 1)
      exit_game("Error\nFloor RGB is already defined\n");
    else if (str[0] == 'C' && config->rgb_c == 1)
      exit_game("Error\nCeiling RGB is already defined\n");
    return (OK);
  }
  return (KO);
}

int check_error_rgb_value(int color_value, char color, char type)
{
  if (color_value > 255)
  {
    if (color == 'r' && type == 'F')
      exit_game("Error\nValue over 255 for floor RED\n");
    else if (color == 'r' && type == 'C')
      exit_game("Error\nValue over 255 for ceiling RED\n");
    else if (color == 'g' && type == 'F')
      exit_game("Error\nValue over 255 for floor GREEN\n");
    else if (color == 'g' && type == 'C')
      exit_game("Error\nValue over 255 for ceiling GREEN\n");
    else if (color == 'b' && type == 'F')
      exit_game("Error\nValue over 255 for floor BLUE\n");
    else if (color == 'b' && type == 'C')
      exit_game("Error\nValue over 255 for ceiling BLUE\n");
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
      exit_game("Error\nNo coma between floor RED and GREEN\n");
    else if (color == 'r' && type == 'C')
      exit_game("Error\nNo coma between ceiling RED and GREEN\n");
    else if (color == 'g' && type == 'F')
      exit_game("Error\nNo coma between floor GREEN and BLUE\n");
    else if (color == 'g' && type == 'C')
      exit_game("Error\nNo coma between ceiling GREEN and BLUE\n");
    return (KO);
  }
}

void error_before_rgb_value(char wrong_c, char color, char type)
{
  if (wrong_c == '-')
    minus_before_rgb_value(color, type);
  else if (color == 'r' && type == 'F')
    exit_game("Error\nInvalid before floor RED\n");
  else if (color == 'r' && type == 'C')
    exit_game("Error\nInvalid before ceiling RED\n");
  if (color == 'g' && type == 'F')
    exit_game("Error\nInvalid between floor RED and BLUE\n");
  else if (color == 'g' && type == 'C')
    exit_game("Error\nInvalid between ceiling RED and BLUE\n");
  if (color == 'b' && type == 'F')
    exit_game("Error\nInvalid after floor BLUE\n");
  else if (color == 'b' && type == 'C')
    exit_game("Error\nInvalid after ceiling BLUE\n");
}

void minus_before_rgb_value(char color, char type)
{
  if (color == 'r' && type == 'F')
    exit_game("Error\nValue below 0 for floor RED\n");
  else if (color == 'r' && type == 'C')
    exit_game("Error\nValue below 0 for ceiling RED\n");
  if (color == 'g' && type == 'F')
    exit_game("Error\nValue below 0 for floor BLUE\n");
  else if (color == 'g' && type == 'C')
    exit_game("Error\nValue below 0 for ceiling BLUE\n");
  if (color == 'b' && type == 'F')
    exit_game("Error\nValue below 0 for floor GREEN\n");
  else if (color == 'b' && type == 'C')
    exit_game("Error\nValue below 0 for ceiling GREEN\n");
}
