/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:18:01 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/22 21:34:47 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

void	cb_move_left(t_player *player)
{
	player->pos.x -= cb_get_player_position(player->plane.x);
	player->pos.y -= cb_get_player_position(player->plane.y);
}

void	cb_move_right(t_player *player)
{
	player->pos.x += cb_get_player_position(player->plane.x);
	player->pos.y += cb_get_player_position(player->plane.y);
}

void	cb_move_forward(t_player *player, char **map)
{
	// new_pos_x = ft_get_new_position(player->dir.x);
	// new_pos_y = ft_get_new_position(player->dir.y);
	// if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
	// 	player->pos.x += new_pos_x;
	// if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
	// 	player->pos.y += new_pos_y;

	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cb_get_player_position(player->dir.x);
	new_pos_y = cb_get_player_position(player->dir.y);
	if (cb_player_can_move(map, new_pos_x + player->pos.x, player->pos.y))
		player->pos.x += new_pos_x;
	if (cb_player_can_move(map, player->pos.x, new_pos_y + player->pos.y))
		player->pos.y += new_pos_y;



}

int	cb_keydown(int key, t_game *game)
{
	// cb_print_msg("Tecla abajo ", NULL);

	if (key == 13) // ? Adelante
	{
		if (cb_player_can_move(game->map, game->player.pos.x, game->player.pos.y))
		{
			game->player.keys.forward = 1;
			cb_move_forward(&game->player, game->map);
			
			// if (cb_player_can_move(game->map, game->player.pos.x, game->player.pos.y))
			// 	cb_move_forward(&game->player, game->map);
		}

	}
	if (key == 1) // ? Atras
	{
		game->player.keys.backward = 1;

	}
	if (key == 2) // ?move right
	{
		game->player.keys.right = 1;
		if (cb_player_can_move(game->map, game->player.pos.x, game->player.pos.y))
			cb_move_right(&game->player);
	}
	if (key == 0) // ?move left
	{
		game->player.keys.left = 1;
		if (cb_player_can_move(game->map, game->player.pos.x, game->player.pos.y))
			cb_move_left(&game->player);

	}
	if (key == 123) // ? rotate left
	{
		game->player.keys.pan_left = 1;
		game->player.dir = cb_get_player_rotation(game->player.dir.x, game->player.dir.y, -ROT_SPEED);
		game->player.plane = cb_get_player_rotation(
			game->player.plane.x, game->player.plane.y, -ROT_SPEED);
	}
	if (key == 124) // ? rotate right
	{
		game->player.keys.pan_right = 1;
		game->player.dir = cb_get_player_rotation(game->player.dir.x, game->player.dir.y, ROT_SPEED);
		game->player.plane = cb_get_player_rotation(
			game->player.plane.x, game->player.plane.y, ROT_SPEED);
	}
	if (key == 53)
		cb_destroy(game);
	return (0);
}

int	cb_keyup(int key, t_game *game)
{
	(void)game;

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

