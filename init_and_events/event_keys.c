#include "../includes/second_cube.h"

int		key_released(int key)
{
	if (key == 13 && win->keybuffer->toward == 1)
		win->keybuffer->toward = 0;
	else if (key == 1 && win->keybuffer->backward == 1)
		win->keybuffer->backward = 0;
	else if (key == 0 && win->keybuffer->left == 1)
		win->keybuffer->left = 0;
	else if (key == 2 && win->keybuffer->right == 1)
		win->keybuffer->right = 0;
	else if ((key == 124 || key == 14) && win->keybuffer->turn_left == 1)
		win->keybuffer->turn_left = 0;
	else if ((key == 123 || key == 12) && win->keybuffer->turn_right == 1)
		win->keybuffer->turn_right = 0;
  else if (key == 15)
		win->player->speed = 0.25;

	return (1);
}

int		key_pressed(int key)
{
	if (key == 17)
		win->keybuffer->exit = 1;
	else if (key == 13 && win->keybuffer->toward == 0)
		win->keybuffer->toward = 1;
	else if (key == 1 && win->keybuffer->backward == 0)
		win->keybuffer->backward = 1;
	else if (key == 0 && win->keybuffer->left == 0)
		win->keybuffer->left = 1;
	else if (key == 2 && win->keybuffer->right == 0)
		win->keybuffer->right = 1;
	else if ((key == 124 || key == 14) && win->keybuffer->turn_left == 0)
		win->keybuffer->turn_left = 1;
	else if ((key == 123 || key == 12) && win->keybuffer->turn_right == 0)
		win->keybuffer->turn_right = 1;
  else if (key == 15)
		win->player->speed = 0.5;
	return (1);
}

int		key_manager(void)
{
	if (win->keybuffer->exit == 1)
    exit_game();
	if (win->keybuffer->toward == 1)
		move_forward();
	if (win->keybuffer->backward == 1)
		move_backward();
	if (win->keybuffer->left == 1)
		move_left();
	if (win->keybuffer->right == 1)
		move_right();
	if (win->keybuffer->turn_left == 1)
		turn_left();
	if (win->keybuffer->turn_right == 1)
		turn_right();
	return (1);
}
