#include "../includes/cub3D.h"

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

int		key_pressed(int key)
{
	if (key == 17)
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

int		key_manager(void)
{
	if (g_key->exit == 1)
    exit_game(NULL);
	if (g_key->toward == 1)
		move_forward();
	if (g_key->backward == 1)
		move_backward();
	if (g_key->left == 1)
		move_left();
	if (g_key->right == 1)
		move_right();
	if (g_key->turn_left == 1)
		turn_left();
	if (g_key->turn_right == 1)
		turn_right();
	return (1);
}
