/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:59:21 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/25 14:59:47 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	cb_move_left(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.plane.x);
	new_pos_y = cb_get_player_new_position(game->player.plane.y);

	if (cb_player_can_move(game->map, game->player.pos.x
			- new_pos_x, game->player.pos.y))
		game->player.pos.x -= new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x
			, game->player.pos.y - new_pos_y))
		game->player.pos.y -= new_pos_y;
}

void	cb_move_right(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.plane.x);
	new_pos_y = cb_get_player_new_position(game->player.plane.y);

	if (cb_player_can_move(game->map, new_pos_x
			+ game->player.pos.x, game->player.pos.y))
		game->player.pos.x += new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x
			, new_pos_y + game->player.pos.y))
		game->player.pos.y += new_pos_y;
}

void	cb_move_forward(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.dir.x);
	new_pos_y = cb_get_player_new_position(game->player.dir.y);

	if (cb_player_can_move(game->map, new_pos_x
			+ game->player.pos.x, game->player.pos.y))
		game->player.pos.x += new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x
			, new_pos_y + game->player.pos.y))
		game->player.pos.y += new_pos_y;
}

void	cb_move_backward(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.dir.x);
	new_pos_y = cb_get_player_new_position(game->player.dir.y);

	if (cb_player_can_move(game->map, game->player.pos.x
			- new_pos_x, game->player.pos.y))
		game->player.pos.x -= new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x
			, game->player.pos.y - new_pos_y))
		game->player.pos.y -= new_pos_y;
}