#include "../../includes/cub3D.h"

/* Initialisation des events */

/* Events lorsque l'utilisateur presse une touche */
/* Lorsqu'une touche est pressée alors la variable correspondante est set à 1 dans la structure g_key */
int		key_pressed(int key)
{
	if (key == KEY_ESC)
		g_key->exit = 1;
	else if (key == KEY_W && g_key->toward == 0)
		g_key->toward = 1;
	else if (key == KEY_S && g_key->backward == 0)
		g_key->backward = 1;
	else if (key == KEY_A && g_key->left == 0)
		g_key->left = 1;
	else if (key == KEY_D && g_key->right == 0)
		g_key->right = 1;
	else if ((key == KEY_LEFT || key == KEY_Q) && g_key->turn_left == 0)
		g_key->turn_left = 1;
	else if ((key == KEY_RIGHT || key == KEY_E) && g_key->turn_right == 0)
		g_key->turn_right = 1;
  else if (key == KEY_R)
		player->speed = 0.5;
	return (1);
}

/* Events lorsque l'utilisateur relache une touche */
/* Lorsqu'une touche n'est plus pressée alors la variable correspondante est set à 0 dans la structure g_key */
int		key_released(int key)
{
	if (key == KEY_W && g_key->toward == 1)
		g_key->toward = 0;
	else if (key == KEY_S && g_key->backward == 1)
		g_key->backward = 0;
	else if (key == KEY_A && g_key->left == 1)
		g_key->left = 0;
	else if (key == KEY_D && g_key->right == 1)
		g_key->right = 0;
	else if ((key == KEY_LEFT || key == KEY_Q) && g_key->turn_left == 1)
		g_key->turn_left = 0;
	else if ((key == KEY_RIGHT || key == KEY_E) && g_key->turn_right == 1)
		g_key->turn_right = 0;
  else if (key == KEY_R)
		player->speed = 0.25;

	return (1);
}

/* Events lorsque l'utilisateur clique sur la croix de fermeture de la fenetre*/
int		end_game(void)
{
  exit_game(NULL);
  return (1);
}
