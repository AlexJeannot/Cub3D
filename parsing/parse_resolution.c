#include "../includes/second_cube.h"

int is_resolution(char *str)
{
  if (str[0] == 'R')
  {
    if (config->resolution == 1)
      exit_game("Resolution deja defini\n");
    return (OK);
  }
  return (KO);
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
    if (str[cmp] != '\0')
      exit_game("Caractère invalide après la définition de la résolution\nExemple de format attendu : R 1920 1080\n");
    config->resolution = 1;
  }
  else
    exit_game("Caractère invalide avant definition de la largeur\nExemple de format attendu : R 1920 1080\n");
}
