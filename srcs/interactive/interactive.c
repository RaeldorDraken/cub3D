/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:18:01 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/23 23:43:30 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	cb_move_left(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.plane.x);
	new_pos_y = cb_get_player_new_position(game->player.plane.y);

	if (cb_player_can_move(game->map, game->player.pos.x - new_pos_x, game->player.pos.y))
		game->player.pos.x -= new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x,  game->player.pos.y - new_pos_y))
		game->player.pos.y -= new_pos_y;
}

void	cb_move_right(t_game *game)
{
	
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.plane.x);
	new_pos_y = cb_get_player_new_position(game->player.plane.y);

	if (cb_player_can_move(game->map, new_pos_x + game->player.pos.x, game->player.pos.y))
		game->player.pos.x += new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x, new_pos_y + game->player.pos.y))
		game->player.pos.y += new_pos_y;	
}

void	cb_move_forward(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.dir.x);
	new_pos_y = cb_get_player_new_position(game->player.dir.y);

	if (cb_player_can_move(game->map, new_pos_x + game->player.pos.x, game->player.pos.y))
		game->player.pos.x += new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x, new_pos_y + game->player.pos.y))
		game->player.pos.y += new_pos_y;
}

void	cb_move_backward(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_new_position(game->player.dir.x);
	new_pos_y = cb_get_player_new_position(game->player.dir.y);

	if (cb_player_can_move(game->map, game->player.pos.x - new_pos_x, game->player.pos.y))
		game->player.pos.x -= new_pos_x;
	if (cb_player_can_move(game->map, game->player.pos.x,  game->player.pos.y - new_pos_y))
		game->player.pos.y -= new_pos_y;
}

int	cb_keydown(int key, t_game *game)
{
	printf("Player can move is %d\n", cb_player_can_move(game->map, game->player.pos.x, game->player.pos.y));

	if (key == 13) // ? Adelante
	{
		game->player.keys.forward = 1;
		cb_move_forward(game);
	}
	if (key == 1) // ? Atras
	{
		game->player.keys.backward = 1;
		cb_move_backward(game);
	}
	if (key == 2) // ?move right
	{
		game->player.keys.right = 1;
		cb_move_right(game);
	}
	if (key == 0) // ?move left
	{
		game->player.keys.left = 1;
		cb_move_left(game);

	}
	if (key == 124) // ? rotate right
	{
		game->player.keys.pan_left = 1;
		game->player.dir = cb_get_player_new_rotation(game->player.dir.x, game->player.dir.y, -ROT_SPEED);
		game->player.plane = cb_get_player_new_rotation(
			game->player.plane.x, game->player.plane.y, -ROT_SPEED);
	}
	if (key == 123) // ? rotate left
	{
		game->player.keys.pan_right = 1;
		game->player.dir = cb_get_player_new_rotation(game->player.dir.x, game->player.dir.y, ROT_SPEED);
		game->player.plane = cb_get_player_new_rotation(
			game->player.plane.x, game->player.plane.y, ROT_SPEED);
	}
	if (key == 53)
		cb_destroy(game);
	return (0);
}

int	cb_keyup(int key, t_game *game)
{
	cb_print_msg("Tecla arriba ", NULL);

	if (key == 13)
	{
		game->player.keys.forward = 0;
		cb_print_msg("Adelante / W\n", NULL);
	}
	if (key == 1)
	{
		game->player.keys.backward = 0;
		cb_print_msg("Atras / S\n", NULL);
	}
	if (key == 2)
	{
		game->player.keys.right = 0;
		cb_print_msg("Derecha / D\n", NULL);
	}
	if (key == 0)
	{
		game->player.keys.left = 0;
		cb_print_msg("Izquierda / A\n", NULL);	}
	if (key == 123)
	{
		game->player.keys.pan_left = 0;
		cb_print_msg("Flecha Rotar izquierda / <- \n", NULL);
	}
	if (key == 124)
	{
		game->player.keys.pan_right = 0;
		cb_print_msg("Flecha Rotar derecha / ->\n", NULL);
	}
	return (0);
}

