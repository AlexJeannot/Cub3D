#include "../includes/second_cube.h"

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

void error_before_rgb_value(char wrong_c, char color, char type)
{
  if (wrong_c == '-')
    minus_before_rgb_value(color, type);
  else if (color == 'r' && type == 'F')
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

void minus_before_rgb_value(char color, char type)
{
  if (color == 'r' && type == 'F')
    exit_game("minus avant r value for floor\n");
  else if (color == 'r' && type == 'C')
    exit_game("minus r value for ceiling\n");
  if (color == 'g' && type == 'F')
    exit_game("minus g value for floor\n");
  else if (color == 'g' && type == 'C')
    exit_game("cminus g value for ceiling\n");
  if (color == 'b' && type == 'F')
    exit_game("minus b value for floor\n");
  else if (color == 'b' && type == 'C')
    exit_game("minus avant b value for ceiling\n");
}
