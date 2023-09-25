/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:18:01 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/25 17:38:05 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	cb_pan_left(t_game *game)
{
	game->player.dir = cb_get_player_new_rotation(
			game->player.dir.x, game->player.dir.y, -ROT_SPEED);
	game->player.plane = cb_get_player_new_rotation(
			game->player.plane.x, game->player.plane.y, -ROT_SPEED);
}

void	cb_pan_right(t_game *game)
{
	game->player.dir = cb_get_player_new_rotation(
			game->player.dir.x, game->player.dir.y, ROT_SPEED);
	game->player.plane = cb_get_player_new_rotation(
			game->player.plane.x, game->player.plane.y, ROT_SPEED);
}

int	cb_keydown(int key, t_game *game)
{
	if (key == 13)
		cb_move_forward(game);
	if (key == 1)
		cb_move_backward(game);
	if (key == 2)
		cb_move_right(game);
	if (key == 0)
		cb_move_left(game);
	if (key == 124)
		cb_pan_left(game);
	if (key == 123)
		cb_pan_right(game);
	if (key == 53)
		cb_destroy(game);
	return (0);
}
