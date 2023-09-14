/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:18:01 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/13 18:11:54 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_keydown(int key, t_game *game)
{
	cb_print_msg("Tecla abajo ", NULL);

	if (key == 13)
	{
		game->player.keys.forward = 1;
		cb_print_msg("Adelante / W\n", NULL);
	}
	if (key == 1)
	{
		game->player.keys.backward = 1;
		cb_print_msg("Atras / S\n", NULL);
	}
	if (key == 2)
	{
		game->player.keys.right = 1;
		cb_print_msg("Derecha / D\n", NULL);
	}
	if (key == 0)
	{
		game->player.keys.left = 1;
		cb_print_msg("Izquierda / A\n", NULL);
	}
	if (key == 123)
	{
		game->player.keys.pan_left = 1;
		cb_print_msg("Flecha Rotar izquierda / <- \n", NULL);
	}
	if (key == 124)
	{
		game->player.keys.pan_right = 1;
		cb_print_msg("Flecha Rotar derecha / ->\n", NULL);
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

