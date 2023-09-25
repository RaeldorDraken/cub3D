/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:51:20 by rabril-h          #+#    #+#             */
/*   Updated: 2023/09/25 16:21:33 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cube.h"

int	cb_init_player(t_game *game)
{
	game->player.pos = cb_get_player_pos(game);
	game->player.player = 1;
	cb_player_dir(game);
	return (0);
}

// int	cb_init_keys(t_game *game)
// {
// 	game->player.keys.forward = 0;
// 	game->player.keys.backward = 0;
// 	game->player.keys.left = 0;
// 	game->player.keys.right = 0;
// 	game->player.keys.pan_left = 0;
// 	game->player.keys.pan_right = 0;

// 	return (0);
// }


int	cb_load_textures(t_game *game, int index)
{
	int	width;
	int	height;

	game->walls[index].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->text_paths[index], &width, &height);
	if (!game->walls[index].img_ptr)
		cb_print_msg("Error: Could not load image", (char *)1);
	game->walls[index].addr
		= mlx_get_data_addr(game->walls[index].img_ptr,
			&game->walls[index].bpp, &game->walls[index].line_len,
			&game->walls[index].endian);
	if (!game->walls[index].addr)
		cb_print_msg("Error getting image address \n", (char *)1);
	return (0);
}

int	cb_setup(t_game *game)
{
	int	i;

	i = -1;
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		cb_print_msg("Error: mlx could not init\n", (char *)1);
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			WIDTH, HEIGHT,
			"Cub3D");
	if (!game->mlx.win_ptr)
		cb_print_msg("Error: mlx window could not init\n", (char *)1);
	game->mlx.image.img_ptr = mlx_new_image(game->mlx.mlx_ptr, WIDTH, HEIGHT);
	if (!game->mlx.image.img_ptr)
		cb_print_msg("Error: mlx image has not been created\n", (char *)1);
	game->mlx.image.addr = mlx_get_data_addr(game->mlx.image.img_ptr,
			&(game->mlx.image.bpp),
			&(game->mlx.image.line_len), &(game->mlx.image.endian));
	if (!game->mlx.image.addr)
		cb_print_msg("Error: mlx image address not created\n", (char *)1);
	while (++i < 4)
		cb_load_textures(game, i);
	cb_init_player(game);
	//cb_init_keys(game);
	return (0);
}
