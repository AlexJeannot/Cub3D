#include "../../includes/cub3D.h"

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
